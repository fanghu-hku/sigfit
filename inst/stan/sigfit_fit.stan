functions {
#include /include/common_functions.stan
}

data {
    int<lower=1, upper=4> family;  // model: 1=multinomial, 2=poisson, 3=negbin, 4=normal
    int<lower=1> C;                // number of mutation categories
    int<lower=1> S;                // number of mutational signatures
    int<lower=1> G;                // number of genomes
    int counts_int[G, C];          // observed mutation counts (discrete case)
    real counts_real[G, C];        // observed mutation counts (continuous case)
    matrix[S, C] signatures;       // signatures to fit (signature per row)
    matrix[G, C] opportunities;    // mutational opportunities (genome per row)
    vector<lower=0>[S] kappa[G];   // prior on exposures (mixing proportions)
}

transformed data {
    // Dynamic dimensions for model-specific parameters:
    // unused parameters have zero length
    int G_mult = (family != 1) ? G : 0;
    int C_phi = (family == 3) ? C : 0;
    int G_sigma = (family == 4) ? G : 0;
}

parameters {
    simplex[S] exposures[G];           // signature exposures (genome per row)
    real<lower=0> multiplier[G_mult];  // exposure multipliers
    vector<lower=0>[G_sigma] sigma;    // standard deviations (normal model)
    vector<lower=0>[C_phi] phi;        // overdispersions (neg bin model)
}

transformed parameters {
    matrix<lower=0>[G, S] activities;  // scaled exposures (# mutations)
    matrix[G, C] expected_counts;
    // Scale exposures into activities
    if (family == 1) {
        // Multinomial model uses unscaled exposures
        activities = array_to_matrix(exposures);
    }
    else if ((family == 2) || (family == 3)) {
        for (g in 1:G) {
            activities[g] = exposures[g]' * sum(counts_int[g]) * multiplier[g];
        }
    }
    else {
        for (g in 1:G) {
            activities[g] = exposures[g]' * sum(counts_real[g]) * multiplier[g];
        }
    }
    // Calculate expected counts (or probabilities)
    expected_counts = activities * signatures .* opportunities;
    if (family == 1) {
        // Multinomial requires a simplex
        for (g in 1:G) {
            expected_counts[g] = scale_row_to_sum_1(expected_counts[g]);
        }
    }
}

model {
    // Exposure priors (all models)
    for (g in 1:G) {
        exposures[g] ~ dirichlet(kappa[g]);
    }

    // Multinomial ('NMF') model
    if (family == 1) {
        for (g in 1:G) {
            counts_int[g] ~ multinomial(expected_counts[g]');
        }
    }

    else {
        multiplier ~ cauchy(0, 2.5);

        // Poisson ('EMu') model
        if (family == 2) {
            for (g in 1:G) {
                counts_int[g] ~ poisson(expected_counts[g]);
            }
        }

        // Negative binomial model
        else if (family == 3) {
            phi ~ cauchy(0, 2.5);
            for (g in 1:G) {
                counts_int[g] ~ neg_binomial_2(expected_counts[g], phi);
            }
        }

        // Normal model
        else {
            sigma ~ cauchy(0, 2.5);
            for (g in 1:G) {
                counts_real[g] ~ normal(expected_counts[g], sigma[g]);
            }
        }
    }
}

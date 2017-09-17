functions {
    #include "common_functions.stan"
}
data {
    int<lower=1> C;            // number of categories
    int<lower=1> S;            // number of fixed signatures
    int<lower=1> G;            // number of genomes
    int<lower=1> N;            // number of extra signatures
    matrix[S, C] fixed_sigs;   // matrix of signatures (rows) by categories (columns)
    int<lower=0> counts[G, C]; // data = counts per genome (rows) in each category (columns)
    matrix[G, C] opps;         // matrix of opportunities per sample (rows) per category
    matrix[N, C] alpha;        // priors for extra signatures
}
transformed data {
    int T = S + N;   // total number of signatures, including extra signatures
    vector[T] kappa = rep_vector(0.5, T);  // Jeffreys prior for exposures
}
parameters {
    simplex[C] extra_sigs[N];  // additional signatures to extract
    simplex[T] exposures[G];   // includes exposures for extra_sigs
    vector<lower=0>[G] multiplier;
}
transformed parameters {
    // Full signatures matrix
    matrix[T, C] signatures = append_row(fixed_sigs, array_to_matrix(extra_sigs));
    
    // Poisson parameters
    matrix[G, C] lambda = array_to_matrix(exposures) * signatures .* opps;
    for (g in 1:G) {
        lambda[g] = lambda[g] * multiplier[g];
    }
}
model {
    // Priors for extra signatures
    for (n in 1:N) {
        extra_sigs[n] ~ dirichlet(alpha[n]);
    }

    for (g in 1:G) {
        // Priors for exposures (Jeffreys)
        exposures[g] ~ dirichlet(kappa);
        multiplier[g] ~ cauchy(0, 1);
        
        // Likelihood
        counts[g] ~ poisson(lambda[g]);
    }
}
generated quantities {
    vector[G] log_lik;
    real bic;
    
    // Compute log_lik
    for (g in 1:G) {
        log_lik[g] = poisson_lpmf(counts[g] | lambda[g]);
    }
    
    // Compute bic with (G*N + N*(C-1)) free parameters
    bic = 2 * sum(log_lik) - log(G) * (G*T + N*(C-1));
}

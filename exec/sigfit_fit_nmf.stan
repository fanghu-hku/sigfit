functions {
    #include "common_functions.stan"
}
data {
    int<lower=1> C;             // number of mutation categories
    int<lower=1> S;             // number of mutational signatures
    int<lower=1> G;             // number of genomes
    matrix[S, C] signatures;    // matrix of signatures (rows) to be fitted
    int<lower=0> counts[G, C];  // matrix of counts per category (columns) per genome sample (rows)
    vector<lower=0>[S] alpha;   // prior on exposures (i.e. mixing proportions of signatures)
}
parameters {
    simplex[S] exposures[G];
}
transformed parameters {
    // array_to_matrix is defined in common_functions.stan and is not in base Stan
    matrix<lower=0, upper=1>[G, C] probs = array_to_matrix(exposures) * signatures;
}
model {
    for (g in 1:G) {
        // Priors
        exposures[g] ~ dirichlet(alpha);
        
        // Likelihood
        counts[g] ~ multinomial(probs[g]');
    }
}
generated quantities {
    vector[G] log_lik;
    matrix[G, C] counts_ppc;
    matrix[G, C] expected_counts;
    
    // Compute log likelihood
    for (g in 1:G) {
        log_lik[g] = multinomial_lpmf(counts[g] | probs[g]');
        counts_ppc[g] = to_row_vector(multinomial_rng(probs[g]', sum(counts[g])));
        expected_counts[g] = probs[g] * sum(counts[g]);
    }

}

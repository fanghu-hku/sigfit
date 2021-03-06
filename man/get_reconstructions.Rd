% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/sigfit_utility.R
\name{get_reconstructions}
\alias{get_reconstructions}
\title{Generate reconstructed mutation catalogues from parameters estimated from MCMC samples}
\usage{
get_reconstructions(mcmc_samples)
}
\arguments{
\item{mcmc_samples}{List with elements \code{`data`} and \code{`results`}, produced via either
\code{\link{fit_signatures}}, \code{\link{extract_signatures}} or \code{\link{fit_extract_signatures}}.}
}
\description{
Generate reconstructed mutation catalogues from parameters estimated from MCMC samples
}

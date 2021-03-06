% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/sigfit_utility.R
\name{convert_signatures}
\alias{convert_signatures}
\title{Convert signatures between models}
\usage{
convert_signatures(signatures, opportunities_from = NULL,
  opportunities_to = NULL)
}
\arguments{
\item{signatures}{Either a numeric matrix of mutational signatures, with one row per signature
and one column per mutation type, or a list of matrices generated via \code{\link{retrieve_pars}}.}

\item{opportunities_from}{Mutational opportunities that are currently imposed on the signatures.
This can be a numeric matrix of mutational opportunities, with one row per signature and
one column per mutation type (if the signatures were inferred together, then every row should
contain the same opportunities). Character values \code{"human-genome"} or \code{"human-exome"}
are also admitted, in which case the mutational opportunities of the reference human
genome/exome will be used for every signature. If this argument is provided, the signatures will
be normalised (divided) by the opportunities. Otherwise (if \code{opportunities_from = NULL}),
the signatures will be interpreted as being already normalised (i.e. not relative to any
opportunities).}

\item{opportunities_to}{Mutational opportunities that are to be imposed on the signatures.
Admits the same values as \code{opportunities_from}. If this argument is provided, the
signatures will be multiplied by the opportunities. Otherwise (if \code{opportunities_to = NULL}),
the signatures will be converted to a normalised representation (i.e. not relative to any
opportunities).}
}
\value{
A numeric matrix of transformed signatures with the same dimensions as \code{signatures}.
}
\description{
\code{convert_signatures} converts mutational signatures between two representations relative to 
different sets of mutational opportunities.
}
\examples{
# Load COSMIC signatures
# (these are relative to the human genome mutational opportunities)
data("cosmic_signatures_v2")

# Plot COSMIC signature 1
barplot(cosmic_signatures_v2[1,])

# Convert signatures from genome-relative to exome-relative representation
exome_sigs <- convert_signatures(cosmic_signatures_v2,
                                 opportunities_from = "human-genome",
                                 opportunities_to = "human-exome")
barplot(exome_sigs[1,])

# Normalise signatures to a sequence-independent representation
normalised_sigs <- convert_signatures(cosmic_signatures_v2,
                                      opportunities_from = "human-genome",
                                      opportunities_to = NULL)
barplot(normalised_sigs[1,])

# Convert back to genome-relative opportunities
genome_sigs <- convert_signatures(normalised_sigs,
                                  opportunities_from = NULL,
                                  opportunities_to = "human-genome")
barplot(genome_sigs[1,])
}

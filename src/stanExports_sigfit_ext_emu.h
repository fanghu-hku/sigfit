// Generated by rstantools.  Do not edit by hand.

/*
    sigfit is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    sigfit is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with sigfit.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef MODELS_HPP
#define MODELS_HPP
#define STAN__SERVICES__COMMAND_HPP
#include <rstan/rstaninc.hpp>
// Code generated by Stan version 2.19.1

#include <stan/model/model_header.hpp>

namespace model_sigfit_ext_emu_namespace {

using std::istream;
using std::string;
using std::stringstream;
using std::vector;
using stan::io::dump;
using stan::math::lgamma;
using stan::model::prob_grad;
using namespace stan::math;

static int current_statement_begin__;

stan::io::program_reader prog_reader__() {
    stan::io::program_reader reader;
    reader.add_event(0, 0, "start", "model_sigfit_ext_emu");
    reader.add_event(1, 1, "include", "/include/common_functions.stan");
    reader.add_event(1, 0, "start", "/include/common_functions.stan");
    reader.add_event(23, 22, "end", "/include/common_functions.stan");
    reader.add_event(23, 2, "restart", "model_sigfit_ext_emu");
    reader.add_event(68, 45, "end", "model_sigfit_ext_emu");
    return reader;
}

template <typename T0__>
Eigen::Matrix<typename boost::math::tools::promote_args<T0__>::type, Eigen::Dynamic, 1>
scale_to_sum_1(const Eigen::Matrix<T0__, Eigen::Dynamic, 1>& v, std::ostream* pstream__) {
    typedef typename boost::math::tools::promote_args<T0__>::type local_scalar_t__;
    typedef local_scalar_t__ fun_return_scalar_t__;
    const static bool propto__ = true;
    (void) propto__;
        local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // suppress unused var warning

    int current_statement_begin__ = -1;
    try {

        current_statement_begin__ = 3;
        return stan::math::promote_scalar<fun_return_scalar_t__>(divide(v, sum(v)));
    } catch (const std::exception& e) {
        stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
        // Next line prevents compiler griping about no return
        throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
    }
}


struct scale_to_sum_1_functor__ {
    template <typename T0__>
        Eigen::Matrix<typename boost::math::tools::promote_args<T0__>::type, Eigen::Dynamic, 1>
    operator()(const Eigen::Matrix<T0__, Eigen::Dynamic, 1>& v, std::ostream* pstream__) const {
        return scale_to_sum_1(v, pstream__);
    }
};

template <typename T0__>
Eigen::Matrix<typename boost::math::tools::promote_args<T0__>::type, 1, Eigen::Dynamic>
scale_row_to_sum_1(const Eigen::Matrix<T0__, 1, Eigen::Dynamic>& r, std::ostream* pstream__) {
    typedef typename boost::math::tools::promote_args<T0__>::type local_scalar_t__;
    typedef local_scalar_t__ fun_return_scalar_t__;
    const static bool propto__ = true;
    (void) propto__;
        local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // suppress unused var warning

    int current_statement_begin__ = -1;
    try {

        current_statement_begin__ = 7;
        return stan::math::promote_scalar<fun_return_scalar_t__>(divide(r, sum(r)));
    } catch (const std::exception& e) {
        stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
        // Next line prevents compiler griping about no return
        throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
    }
}


struct scale_row_to_sum_1_functor__ {
    template <typename T0__>
        Eigen::Matrix<typename boost::math::tools::promote_args<T0__>::type, 1, Eigen::Dynamic>
    operator()(const Eigen::Matrix<T0__, 1, Eigen::Dynamic>& r, std::ostream* pstream__) const {
        return scale_row_to_sum_1(r, pstream__);
    }
};

template <typename T0__>
Eigen::Matrix<typename boost::math::tools::promote_args<T0__>::type, Eigen::Dynamic, Eigen::Dynamic>
array_to_matrix(const std::vector<Eigen::Matrix<T0__, Eigen::Dynamic, 1> >& x, std::ostream* pstream__) {
    typedef typename boost::math::tools::promote_args<T0__>::type local_scalar_t__;
    typedef local_scalar_t__ fun_return_scalar_t__;
    const static bool propto__ = true;
    (void) propto__;
        local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // suppress unused var warning

    int current_statement_begin__ = -1;
    try {
        {
        current_statement_begin__ = 19;
        validate_non_negative_index("y", "size(x)", size(x));
        validate_non_negative_index("y", "rows(get_base1(x, 1, \"x\", 1))", rows(get_base1(x, 1, "x", 1)));
        Eigen::Matrix<local_scalar_t__, Eigen::Dynamic, Eigen::Dynamic> y(size(x), rows(get_base1(x, 1, "x", 1)));
        stan::math::initialize(y, DUMMY_VAR__);
        stan::math::fill(y, DUMMY_VAR__);


        current_statement_begin__ = 20;
        for (int m = 1; m <= size(x); ++m) {
            current_statement_begin__ = 21;
            stan::model::assign(y, 
                        stan::model::cons_list(stan::model::index_uni(m), stan::model::nil_index_list()), 
                        transpose(get_base1(x, m, "x", 1)), 
                        "assigning variable y");
        }
        current_statement_begin__ = 22;
        return stan::math::promote_scalar<fun_return_scalar_t__>(y);
        }
    } catch (const std::exception& e) {
        stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
        // Next line prevents compiler griping about no return
        throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
    }
}


struct array_to_matrix_functor__ {
    template <typename T0__>
        Eigen::Matrix<typename boost::math::tools::promote_args<T0__>::type, Eigen::Dynamic, Eigen::Dynamic>
    operator()(const std::vector<Eigen::Matrix<T0__, Eigen::Dynamic, 1> >& x, std::ostream* pstream__) const {
        return array_to_matrix(x, pstream__);
    }
};

#include <stan_meta_header.hpp>
 class model_sigfit_ext_emu : public prob_grad {
private:
        int C;
        int S;
        int G;
        std::vector<std::vector<int> > counts;
        matrix_d opps;
        matrix_d alpha;
public:
    model_sigfit_ext_emu(stan::io::var_context& context__,
        std::ostream* pstream__ = 0)
        : prob_grad(0) {
        ctor_body(context__, 0, pstream__);
    }

    model_sigfit_ext_emu(stan::io::var_context& context__,
        unsigned int random_seed__,
        std::ostream* pstream__ = 0)
        : prob_grad(0) {
        ctor_body(context__, random_seed__, pstream__);
    }

    void ctor_body(stan::io::var_context& context__,
                   unsigned int random_seed__,
                   std::ostream* pstream__) {
        typedef double local_scalar_t__;

        boost::ecuyer1988 base_rng__ =
          stan::services::util::create_rng(random_seed__, 0);
        (void) base_rng__;  // suppress unused var warning

        current_statement_begin__ = -1;

        static const char* function__ = "model_sigfit_ext_emu_namespace::model_sigfit_ext_emu";
        (void) function__;  // dummy to suppress unused var warning
        size_t pos__;
        (void) pos__;  // dummy to suppress unused var warning
        std::vector<int> vals_i__;
        std::vector<double> vals_r__;
        local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // suppress unused var warning

        try {
            // initialize data block variables from context__
            current_statement_begin__ = 26;
            context__.validate_dims("data initialization", "C", "int", context__.to_vec());
            C = int(0);
            vals_i__ = context__.vals_i("C");
            pos__ = 0;
            C = vals_i__[pos__++];
            check_greater_or_equal(function__, "C", C, 1);

            current_statement_begin__ = 27;
            context__.validate_dims("data initialization", "S", "int", context__.to_vec());
            S = int(0);
            vals_i__ = context__.vals_i("S");
            pos__ = 0;
            S = vals_i__[pos__++];
            check_greater_or_equal(function__, "S", S, 1);

            current_statement_begin__ = 28;
            context__.validate_dims("data initialization", "G", "int", context__.to_vec());
            G = int(0);
            vals_i__ = context__.vals_i("G");
            pos__ = 0;
            G = vals_i__[pos__++];
            check_greater_or_equal(function__, "G", G, 1);

            current_statement_begin__ = 29;
            validate_non_negative_index("counts", "G", G);
            validate_non_negative_index("counts", "C", C);
            context__.validate_dims("data initialization", "counts", "int", context__.to_vec(G,C));
            counts = std::vector<std::vector<int> >(G, std::vector<int>(C, int(0)));
            vals_i__ = context__.vals_i("counts");
            pos__ = 0;
            size_t counts_k_0_max__ = G;
            size_t counts_k_1_max__ = C;
            for (size_t k_1__ = 0; k_1__ < counts_k_1_max__; ++k_1__) {
                for (size_t k_0__ = 0; k_0__ < counts_k_0_max__; ++k_0__) {
                    counts[k_0__][k_1__] = vals_i__[pos__++];
                }
            }
            size_t counts_i_0_max__ = G;
            size_t counts_i_1_max__ = C;
            for (size_t i_0__ = 0; i_0__ < counts_i_0_max__; ++i_0__) {
                for (size_t i_1__ = 0; i_1__ < counts_i_1_max__; ++i_1__) {
                    check_greater_or_equal(function__, "counts[i_0__][i_1__]", counts[i_0__][i_1__], 0);
                }
            }

            current_statement_begin__ = 30;
            validate_non_negative_index("opps", "G", G);
            validate_non_negative_index("opps", "C", C);
            context__.validate_dims("data initialization", "opps", "matrix_d", context__.to_vec(G,C));
            opps = Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic>(G, C);
            vals_r__ = context__.vals_r("opps");
            pos__ = 0;
            size_t opps_j_2_max__ = C;
            size_t opps_j_1_max__ = G;
            for (size_t j_2__ = 0; j_2__ < opps_j_2_max__; ++j_2__) {
                for (size_t j_1__ = 0; j_1__ < opps_j_1_max__; ++j_1__) {
                    opps(j_1__, j_2__) = vals_r__[pos__++];
                }
            }

            current_statement_begin__ = 31;
            validate_non_negative_index("alpha", "S", S);
            validate_non_negative_index("alpha", "C", C);
            context__.validate_dims("data initialization", "alpha", "matrix_d", context__.to_vec(S,C));
            alpha = Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic>(S, C);
            vals_r__ = context__.vals_r("alpha");
            pos__ = 0;
            size_t alpha_j_2_max__ = C;
            size_t alpha_j_1_max__ = S;
            for (size_t j_2__ = 0; j_2__ < alpha_j_2_max__; ++j_2__) {
                for (size_t j_1__ = 0; j_1__ < alpha_j_1_max__; ++j_1__) {
                    alpha(j_1__, j_2__) = vals_r__[pos__++];
                }
            }


            // initialize transformed data variables
            // execute transformed data statements

            // validate transformed data

            // validate, set parameter ranges
            num_params_r__ = 0U;
            param_ranges_i__.clear();
            current_statement_begin__ = 34;
            validate_non_negative_index("signatures", "C", C);
            validate_non_negative_index("signatures", "S", S);
            num_params_r__ += ((C - 1) * S);
            current_statement_begin__ = 35;
            validate_non_negative_index("activities", "G", G);
            validate_non_negative_index("activities", "S", S);
            num_params_r__ += (G * S);
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
            // Next line prevents compiler griping about no return
            throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
        }
    }

    ~model_sigfit_ext_emu() { }


    void transform_inits(const stan::io::var_context& context__,
                         std::vector<int>& params_i__,
                         std::vector<double>& params_r__,
                         std::ostream* pstream__) const {
        typedef double local_scalar_t__;
        stan::io::writer<double> writer__(params_r__, params_i__);
        size_t pos__;
        (void) pos__; // dummy call to supress warning
        std::vector<double> vals_r__;
        std::vector<int> vals_i__;

        current_statement_begin__ = 34;
        if (!(context__.contains_r("signatures")))
            stan::lang::rethrow_located(std::runtime_error(std::string("Variable signatures missing")), current_statement_begin__, prog_reader__());
        vals_r__ = context__.vals_r("signatures");
        pos__ = 0U;
        validate_non_negative_index("signatures", "C", C);
        validate_non_negative_index("signatures", "S", S);
        context__.validate_dims("parameter initialization", "signatures", "vector_d", context__.to_vec(S,C));
        std::vector<Eigen::Matrix<double, Eigen::Dynamic, 1> > signatures(S, Eigen::Matrix<double, Eigen::Dynamic, 1>(C));
        size_t signatures_j_1_max__ = C;
        size_t signatures_k_0_max__ = S;
        for (size_t j_1__ = 0; j_1__ < signatures_j_1_max__; ++j_1__) {
            for (size_t k_0__ = 0; k_0__ < signatures_k_0_max__; ++k_0__) {
                signatures[k_0__](j_1__) = vals_r__[pos__++];
            }
        }
        size_t signatures_i_0_max__ = S;
        for (size_t i_0__ = 0; i_0__ < signatures_i_0_max__; ++i_0__) {
            try {
                writer__.simplex_unconstrain(signatures[i_0__]);
            } catch (const std::exception& e) {
                stan::lang::rethrow_located(std::runtime_error(std::string("Error transforming variable signatures: ") + e.what()), current_statement_begin__, prog_reader__());
            }
        }

        current_statement_begin__ = 35;
        if (!(context__.contains_r("activities")))
            stan::lang::rethrow_located(std::runtime_error(std::string("Variable activities missing")), current_statement_begin__, prog_reader__());
        vals_r__ = context__.vals_r("activities");
        pos__ = 0U;
        validate_non_negative_index("activities", "G", G);
        validate_non_negative_index("activities", "S", S);
        context__.validate_dims("parameter initialization", "activities", "matrix_d", context__.to_vec(G,S));
        Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> activities(G, S);
        size_t activities_j_2_max__ = S;
        size_t activities_j_1_max__ = G;
        for (size_t j_2__ = 0; j_2__ < activities_j_2_max__; ++j_2__) {
            for (size_t j_1__ = 0; j_1__ < activities_j_1_max__; ++j_1__) {
                activities(j_1__, j_2__) = vals_r__[pos__++];
            }
        }
        try {
            writer__.matrix_lb_unconstrain(0, activities);
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(std::runtime_error(std::string("Error transforming variable activities: ") + e.what()), current_statement_begin__, prog_reader__());
        }

        params_r__ = writer__.data_r();
        params_i__ = writer__.data_i();
    }

    void transform_inits(const stan::io::var_context& context,
                         Eigen::Matrix<double, Eigen::Dynamic, 1>& params_r,
                         std::ostream* pstream__) const {
      std::vector<double> params_r_vec;
      std::vector<int> params_i_vec;
      transform_inits(context, params_i_vec, params_r_vec, pstream__);
      params_r.resize(params_r_vec.size());
      for (int i = 0; i < params_r.size(); ++i)
        params_r(i) = params_r_vec[i];
    }


    template <bool propto__, bool jacobian__, typename T__>
    T__ log_prob(std::vector<T__>& params_r__,
                 std::vector<int>& params_i__,
                 std::ostream* pstream__ = 0) const {

        typedef T__ local_scalar_t__;

        local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // dummy to suppress unused var warning

        T__ lp__(0.0);
        stan::math::accumulator<T__> lp_accum__;
        try {
            stan::io::reader<local_scalar_t__> in__(params_r__, params_i__);

            // model parameters
            current_statement_begin__ = 34;
            std::vector<Eigen::Matrix<local_scalar_t__, Eigen::Dynamic, 1> > signatures;
            size_t signatures_d_0_max__ = S;
            signatures.reserve(signatures_d_0_max__);
            for (size_t d_0__ = 0; d_0__ < signatures_d_0_max__; ++d_0__) {
                if (jacobian__)
                    signatures.push_back(in__.simplex_constrain(C, lp__));
                else
                    signatures.push_back(in__.simplex_constrain(C));
            }

            current_statement_begin__ = 35;
            Eigen::Matrix<local_scalar_t__, Eigen::Dynamic, Eigen::Dynamic> activities;
            (void) activities;  // dummy to suppress unused var warning
            if (jacobian__)
                activities = in__.matrix_lb_constrain(0, G, S, lp__);
            else
                activities = in__.matrix_lb_constrain(0, G, S);

            // transformed parameters
            current_statement_begin__ = 40;
            validate_non_negative_index("expected_counts", "G", G);
            validate_non_negative_index("expected_counts", "C", C);
            Eigen::Matrix<local_scalar_t__, Eigen::Dynamic, Eigen::Dynamic> expected_counts(G, C);
            stan::math::initialize(expected_counts, DUMMY_VAR__);
            stan::math::fill(expected_counts, DUMMY_VAR__);
            stan::math::assign(expected_counts,elt_multiply(multiply(activities, array_to_matrix(signatures, pstream__)), opps));

            // validate transformed parameters
            const char* function__ = "validate transformed params";
            (void) function__;  // dummy to suppress unused var warning

            current_statement_begin__ = 40;
            size_t expected_counts_j_1_max__ = G;
            size_t expected_counts_j_2_max__ = C;
            for (size_t j_1__ = 0; j_1__ < expected_counts_j_1_max__; ++j_1__) {
                for (size_t j_2__ = 0; j_2__ < expected_counts_j_2_max__; ++j_2__) {
                    if (stan::math::is_uninitialized(expected_counts(j_1__, j_2__))) {
                        std::stringstream msg__;
                        msg__ << "Undefined transformed parameter: expected_counts" << "(" << j_1__ << ", " << j_2__ << ")";
                        stan::lang::rethrow_located(std::runtime_error(std::string("Error initializing variable expected_counts: ") + msg__.str()), current_statement_begin__, prog_reader__());
                    }
                }
            }

            // model body

            current_statement_begin__ = 48;
            for (int s = 1; s <= S; ++s) {

                current_statement_begin__ = 50;
                lp_accum__.add(dirichlet_log<propto__>(get_base1(signatures, s, "signatures", 1), transpose(get_base1(alpha, s, "alpha", 1))));
            }
            current_statement_begin__ = 53;
            for (int g = 1; g <= G; ++g) {

                current_statement_begin__ = 55;
                lp_accum__.add(cauchy_log<propto__>(get_base1(activities, g, "activities", 1), 0, 1));
                current_statement_begin__ = 58;
                lp_accum__.add(poisson_log<propto__>(get_base1(counts, g, "counts", 1), get_base1(expected_counts, g, "expected_counts", 1)));
            }

        } catch (const std::exception& e) {
            stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
            // Next line prevents compiler griping about no return
            throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
        }

        lp_accum__.add(lp__);
        return lp_accum__.sum();

    } // log_prob()

    template <bool propto, bool jacobian, typename T_>
    T_ log_prob(Eigen::Matrix<T_,Eigen::Dynamic,1>& params_r,
               std::ostream* pstream = 0) const {
      std::vector<T_> vec_params_r;
      vec_params_r.reserve(params_r.size());
      for (int i = 0; i < params_r.size(); ++i)
        vec_params_r.push_back(params_r(i));
      std::vector<int> vec_params_i;
      return log_prob<propto,jacobian,T_>(vec_params_r, vec_params_i, pstream);
    }


    void get_param_names(std::vector<std::string>& names__) const {
        names__.resize(0);
        names__.push_back("signatures");
        names__.push_back("activities");
        names__.push_back("expected_counts");
        names__.push_back("exposures");
    }


    void get_dims(std::vector<std::vector<size_t> >& dimss__) const {
        dimss__.resize(0);
        std::vector<size_t> dims__;
        dims__.resize(0);
        dims__.push_back(S);
        dims__.push_back(C);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dims__.push_back(G);
        dims__.push_back(S);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dims__.push_back(G);
        dims__.push_back(C);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dims__.push_back(G);
        dims__.push_back(S);
        dimss__.push_back(dims__);
    }

    template <typename RNG>
    void write_array(RNG& base_rng__,
                     std::vector<double>& params_r__,
                     std::vector<int>& params_i__,
                     std::vector<double>& vars__,
                     bool include_tparams__ = true,
                     bool include_gqs__ = true,
                     std::ostream* pstream__ = 0) const {
        typedef double local_scalar_t__;

        vars__.resize(0);
        stan::io::reader<local_scalar_t__> in__(params_r__, params_i__);
        static const char* function__ = "model_sigfit_ext_emu_namespace::write_array";
        (void) function__;  // dummy to suppress unused var warning

        // read-transform, write parameters
        std::vector<Eigen::Matrix<double, Eigen::Dynamic, 1> > signatures;
        size_t signatures_d_0_max__ = S;
        signatures.reserve(signatures_d_0_max__);
        for (size_t d_0__ = 0; d_0__ < signatures_d_0_max__; ++d_0__) {
            signatures.push_back(in__.simplex_constrain(C));
        }
        size_t signatures_j_1_max__ = C;
        size_t signatures_k_0_max__ = S;
        for (size_t j_1__ = 0; j_1__ < signatures_j_1_max__; ++j_1__) {
            for (size_t k_0__ = 0; k_0__ < signatures_k_0_max__; ++k_0__) {
                vars__.push_back(signatures[k_0__](j_1__));
            }
        }

        Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> activities = in__.matrix_lb_constrain(0, G, S);
        size_t activities_j_2_max__ = S;
        size_t activities_j_1_max__ = G;
        for (size_t j_2__ = 0; j_2__ < activities_j_2_max__; ++j_2__) {
            for (size_t j_1__ = 0; j_1__ < activities_j_1_max__; ++j_1__) {
                vars__.push_back(activities(j_1__, j_2__));
            }
        }

        double lp__ = 0.0;
        (void) lp__;  // dummy to suppress unused var warning
        stan::math::accumulator<double> lp_accum__;

        local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // suppress unused var warning

        if (!include_tparams__ && !include_gqs__) return;

        try {
            // declare and define transformed parameters
            current_statement_begin__ = 40;
            validate_non_negative_index("expected_counts", "G", G);
            validate_non_negative_index("expected_counts", "C", C);
            Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> expected_counts(G, C);
            stan::math::initialize(expected_counts, DUMMY_VAR__);
            stan::math::fill(expected_counts, DUMMY_VAR__);
            stan::math::assign(expected_counts,elt_multiply(multiply(activities, array_to_matrix(signatures, pstream__)), opps));

            if (!include_gqs__ && !include_tparams__) return;
            // validate transformed parameters
            const char* function__ = "validate transformed params";
            (void) function__;  // dummy to suppress unused var warning

            // write transformed parameters
            if (include_tparams__) {
                size_t expected_counts_j_2_max__ = C;
                size_t expected_counts_j_1_max__ = G;
                for (size_t j_2__ = 0; j_2__ < expected_counts_j_2_max__; ++j_2__) {
                    for (size_t j_1__ = 0; j_1__ < expected_counts_j_1_max__; ++j_1__) {
                        vars__.push_back(expected_counts(j_1__, j_2__));
                    }
                }
            }
            if (!include_gqs__) return;
            // declare and define generated quantities
            current_statement_begin__ = 62;
            validate_non_negative_index("exposures", "G", G);
            validate_non_negative_index("exposures", "S", S);
            Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> exposures(G, S);
            stan::math::initialize(exposures, DUMMY_VAR__);
            stan::math::fill(exposures, DUMMY_VAR__);

            // generated quantities statements
            current_statement_begin__ = 63;
            for (int g = 1; g <= G; ++g) {

                current_statement_begin__ = 64;
                stan::model::assign(exposures, 
                            stan::model::cons_list(stan::model::index_uni(g), stan::model::nil_index_list()), 
                            scale_row_to_sum_1(get_base1(activities, g, "activities", 1), pstream__), 
                            "assigning variable exposures");
            }

            // validate, write generated quantities
            current_statement_begin__ = 62;
            size_t exposures_j_2_max__ = S;
            size_t exposures_j_1_max__ = G;
            for (size_t j_2__ = 0; j_2__ < exposures_j_2_max__; ++j_2__) {
                for (size_t j_1__ = 0; j_1__ < exposures_j_1_max__; ++j_1__) {
                    vars__.push_back(exposures(j_1__, j_2__));
                }
            }

        } catch (const std::exception& e) {
            stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
            // Next line prevents compiler griping about no return
            throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
        }
    }

    template <typename RNG>
    void write_array(RNG& base_rng,
                     Eigen::Matrix<double,Eigen::Dynamic,1>& params_r,
                     Eigen::Matrix<double,Eigen::Dynamic,1>& vars,
                     bool include_tparams = true,
                     bool include_gqs = true,
                     std::ostream* pstream = 0) const {
      std::vector<double> params_r_vec(params_r.size());
      for (int i = 0; i < params_r.size(); ++i)
        params_r_vec[i] = params_r(i);
      std::vector<double> vars_vec;
      std::vector<int> params_i_vec;
      write_array(base_rng, params_r_vec, params_i_vec, vars_vec, include_tparams, include_gqs, pstream);
      vars.resize(vars_vec.size());
      for (int i = 0; i < vars.size(); ++i)
        vars(i) = vars_vec[i];
    }

    static std::string model_name() {
        return "model_sigfit_ext_emu";
    }


    void constrained_param_names(std::vector<std::string>& param_names__,
                                 bool include_tparams__ = true,
                                 bool include_gqs__ = true) const {
        std::stringstream param_name_stream__;
        size_t signatures_j_1_max__ = C;
        size_t signatures_k_0_max__ = S;
        for (size_t j_1__ = 0; j_1__ < signatures_j_1_max__; ++j_1__) {
            for (size_t k_0__ = 0; k_0__ < signatures_k_0_max__; ++k_0__) {
                param_name_stream__.str(std::string());
                param_name_stream__ << "signatures" << '.' << k_0__ + 1 << '.' << j_1__ + 1;
                param_names__.push_back(param_name_stream__.str());
            }
        }
        size_t activities_j_2_max__ = S;
        size_t activities_j_1_max__ = G;
        for (size_t j_2__ = 0; j_2__ < activities_j_2_max__; ++j_2__) {
            for (size_t j_1__ = 0; j_1__ < activities_j_1_max__; ++j_1__) {
                param_name_stream__.str(std::string());
                param_name_stream__ << "activities" << '.' << j_1__ + 1 << '.' << j_2__ + 1;
                param_names__.push_back(param_name_stream__.str());
            }
        }

        if (!include_gqs__ && !include_tparams__) return;

        if (include_tparams__) {
            size_t expected_counts_j_2_max__ = C;
            size_t expected_counts_j_1_max__ = G;
            for (size_t j_2__ = 0; j_2__ < expected_counts_j_2_max__; ++j_2__) {
                for (size_t j_1__ = 0; j_1__ < expected_counts_j_1_max__; ++j_1__) {
                    param_name_stream__.str(std::string());
                    param_name_stream__ << "expected_counts" << '.' << j_1__ + 1 << '.' << j_2__ + 1;
                    param_names__.push_back(param_name_stream__.str());
                }
            }
        }

        if (!include_gqs__) return;
        size_t exposures_j_2_max__ = S;
        size_t exposures_j_1_max__ = G;
        for (size_t j_2__ = 0; j_2__ < exposures_j_2_max__; ++j_2__) {
            for (size_t j_1__ = 0; j_1__ < exposures_j_1_max__; ++j_1__) {
                param_name_stream__.str(std::string());
                param_name_stream__ << "exposures" << '.' << j_1__ + 1 << '.' << j_2__ + 1;
                param_names__.push_back(param_name_stream__.str());
            }
        }
    }


    void unconstrained_param_names(std::vector<std::string>& param_names__,
                                   bool include_tparams__ = true,
                                   bool include_gqs__ = true) const {
        std::stringstream param_name_stream__;
        size_t signatures_j_1_max__ = (C - 1);
        size_t signatures_k_0_max__ = S;
        for (size_t j_1__ = 0; j_1__ < signatures_j_1_max__; ++j_1__) {
            for (size_t k_0__ = 0; k_0__ < signatures_k_0_max__; ++k_0__) {
                param_name_stream__.str(std::string());
                param_name_stream__ << "signatures" << '.' << k_0__ + 1 << '.' << j_1__ + 1;
                param_names__.push_back(param_name_stream__.str());
            }
        }
        size_t activities_j_2_max__ = S;
        size_t activities_j_1_max__ = G;
        for (size_t j_2__ = 0; j_2__ < activities_j_2_max__; ++j_2__) {
            for (size_t j_1__ = 0; j_1__ < activities_j_1_max__; ++j_1__) {
                param_name_stream__.str(std::string());
                param_name_stream__ << "activities" << '.' << j_1__ + 1 << '.' << j_2__ + 1;
                param_names__.push_back(param_name_stream__.str());
            }
        }

        if (!include_gqs__ && !include_tparams__) return;

        if (include_tparams__) {
            size_t expected_counts_j_2_max__ = C;
            size_t expected_counts_j_1_max__ = G;
            for (size_t j_2__ = 0; j_2__ < expected_counts_j_2_max__; ++j_2__) {
                for (size_t j_1__ = 0; j_1__ < expected_counts_j_1_max__; ++j_1__) {
                    param_name_stream__.str(std::string());
                    param_name_stream__ << "expected_counts" << '.' << j_1__ + 1 << '.' << j_2__ + 1;
                    param_names__.push_back(param_name_stream__.str());
                }
            }
        }

        if (!include_gqs__) return;
        size_t exposures_j_2_max__ = S;
        size_t exposures_j_1_max__ = G;
        for (size_t j_2__ = 0; j_2__ < exposures_j_2_max__; ++j_2__) {
            for (size_t j_1__ = 0; j_1__ < exposures_j_1_max__; ++j_1__) {
                param_name_stream__.str(std::string());
                param_name_stream__ << "exposures" << '.' << j_1__ + 1 << '.' << j_2__ + 1;
                param_names__.push_back(param_name_stream__.str());
            }
        }
    }

}; // model

}  // namespace

typedef model_sigfit_ext_emu_namespace::model_sigfit_ext_emu stan_model;


#endif

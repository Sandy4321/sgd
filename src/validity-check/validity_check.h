#ifndef VALIDITY_CHECK_VALIDITY_CHECK_H
#define VALIDITY_CHECK_VALIDITY_CHECK_H

#include "basedef.h"
#include "data/data_set.h"
#include "validity-check/glm_validity_check_model.h"
#include "validity-check/ee_validity_check_model.h"

template<typename EXPERIMENT>
bool validity_check(const data_set& data, const mat& theta, bool good_gradient,
  unsigned t, const EXPERIMENT& exprm) {
  // Check if gradient is finite.
  if (!good_gradient) {
    Rcpp::Rcout << "NA or infinite gradient" << std::endl;
    return false;
  }

  // Check if all estimates are finite.
  if (!is_finite(theta)) {
    Rcpp::Rcout << "warning: non-finite coefficients at iteration " << t << std::endl;
  }

  return validity_check_model(data, theta, t, exprm);
}

#endif
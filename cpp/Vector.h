/**
 * @file    Vector.h
 * @brief   typedef and functions to augment Boost's ublas::vector<double>
 * @author  Kai Ni
 * @author  Frank Dellaert
 */

// \callgraph

#pragma once

#include <boost/numeric/ublas/vector.hpp>
#include <boost/random/linear_congruential.hpp>

// Vector is a *global* typedef
// wrap-matlab does this typedef as well
#if ! defined (MEX_H)
typedef boost::numeric::ublas::vector<double> Vector;
#endif

namespace gtsam {


void odprintf(const char *format, ...);

/**
 *  constructor with size and initial data, row order !
 */
Vector Vector_( size_t m, const double* const data);

/**
 *  nice constructor, dangerous as number of arguments must be exactly right
 *  and you have to pass doubles !!! always use 0.0 never 0
 */
Vector Vector_(size_t m, ...);

/**
 * Create zero vector
 * @ param size
 */
Vector zero(size_t n);
	
/**
 * check if all zero
 */
bool zero(const Vector& v);
	
/**
 * print with optional string
 */
void print(const Vector& v, const std::string& s = "");

/**
 * returns a string suitable for printing
 */
std::string dump(const Vector& v);

/**
 * operator==()
 */
bool operator==(const Vector& vec1,const Vector& vec2);

/**
 * VecA == VecB up to tolerance
 */
bool equal_with_abs_tol(const Vector& vec1, const Vector& vec2, double tol=1e-9);

/**
 * Same, prints if error
 * @param vec1 Vector
 * @param vec2 Vector
 * @param tol 1e-9
 * @return bool
 */
bool assert_equal(const Vector& vec1, const Vector& vec2, double tol=1e-9);

/**
 * vector multiplication by scalar
inline Vector operator*(double s, const Vector& vec ) {
return vec*s;
}
*/

/**
 * extract subvector, slice semantics, i.e. range = [i1,i2[ excluding i2
 * @param v Vector
 * @param i1 first row index
 * @param i2 last  row index + 1
 * @return subvector v(i1:i2)
 */
Vector sub(const Vector &v, size_t i1, size_t i2);

/**
 * house(x,j) computes HouseHolder vector v and scaling factor beta
 *  from x, such that the corresponding Householder reflection zeroes out
 *  all but x.(j), j is base 0. Golub & Van Loan p 210.
 */
std::pair<double,Vector> house(Vector &x);

/**
 * concatenate Vectors
 */
Vector concatVectors(size_t nrVectors, ...);


/**
 * random vector
 */
Vector rand_vector_norm(size_t dim, double mean = 0, double sigma = 1);

} // namespace gtsam

static boost::minstd_rand generator(42u);


#ifndef _VEC_4F_HPP_
#define _VEC_4F_HPP_

#include <array>
#include <cmath>
#include <iostream>

namespace rtl
{
class vec_4f
{
 public:
  vec_4f();
  vec_4f(double, double, double);

  const vec_4f& operator+() const { return *this; };
  vec_4f operator-() const;
  double operator[](int i) const { return element[i]; }
  double& operator[](int i) { return element[i]; }

  vec_4f& operator+=(const vec_4f& vec_2);
  vec_4f& operator-=(const vec_4f& vec_2);
  vec_4f& operator*=(const vec_4f& vec_2);
  vec_4f& operator/=(const vec_4f& vec_2);

  vec_4f operator+(const vec_4f& vec_2);
  vec_4f operator-(const vec_4f& vec_2);
  vec_4f operator*(const vec_4f& vec_2);
  vec_4f operator/(const vec_4f& vec_2);

  vec_4f& operator*=(const double element_2);
  vec_4f& operator/=(const double element_2);

  vec_4f operator*(const double element_2);
  vec_4f operator/(const double element_2);

  double length() const;
  double squared_length() const;
  void makeUnitVector();
  vec_4f unitVector() const;

  double dot(const vec_4f& vec2) const;
  vec_4f cross(const vec_4f& vec2) const;

  double x() const { return element[0]; }
  double y() const { return element[1]; }
  double z() const { return element[2]; }

  double r() const { return element[0]; }
  double g() const { return element[1]; }
  double b() const { return element[2]; }

 private:
  std::array<double, 3> element;
};
}  // namespace rtl

#endif  // _VEC_4F_

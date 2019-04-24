#include "vec_4f.hpp"

namespace rtl
{
vec_4f::vec_4f() : element{0, 0, 0} {}

vec_4f::vec_4f(double element_1, double element_2, double element_3)
: element{element_1, element_2, element_3}
{
}

vec_4f vec_4f::operator-() const
{
  return vec_4f(-element[0], -element[1], -element[2]);
}

vec_4f& vec_4f::operator+=(const vec_4f& vec_2)
{
  this->element[0] += vec_2.element[0];
  this->element[1] += vec_2.element[1];
  this->element[2] += vec_2.element[2];
  return *this;
}

vec_4f& vec_4f::operator-=(const vec_4f& vec_2)
{
  this->element[0] -= vec_2.element[0];
  this->element[1] -= vec_2.element[1];
  this->element[2] -= vec_2.element[2];
  return *this;
}

vec_4f& vec_4f::operator*=(const vec_4f& vec_2)
{
  this->element[0] *= vec_2.element[0];
  this->element[1] *= vec_2.element[1];
  this->element[2] *= vec_2.element[2];
  return *this;
}

vec_4f& vec_4f::operator/=(const vec_4f& vec_2)
{
  this->element[0] /= vec_2.element[0];
  this->element[1] /= vec_2.element[1];
  this->element[2] /= vec_2.element[2];
  return *this;
}

vec_4f vec_4f::operator+(const vec_4f& vec_2)
{
  return vec_4f(this->element[0] + vec_2.element[0],
                this->element[1] + vec_2.element[1],
                this->element[2] + vec_2.element[2]);
}

vec_4f vec_4f::operator-(const vec_4f& vec_2)
{
  return vec_4f(this->element[0] - vec_2.element[0],
                this->element[1] - vec_2.element[1],
                this->element[2] - vec_2.element[2]);
}

vec_4f vec_4f::operator*(const vec_4f& vec_2)
{
  return vec_4f(this->element[0] * vec_2.element[0],
                this->element[1] * vec_2.element[1],
                this->element[2] * vec_2.element[2]);
}

vec_4f vec_4f::operator/(const vec_4f& vec_2)
{
  return vec_4f(this->element[0] / vec_2.element[0],
                this->element[1] / vec_2.element[1],
                this->element[2] / vec_2.element[2]);
}

vec_4f& vec_4f::operator*=(const double element_2)
{
  this->element[0] *= element_2;
  this->element[1] *= element_2;
  this->element[2] *= element_2;
  return *this;
}

vec_4f& vec_4f::operator/=(const double element_2)
{
  double temp = 1 / element_2;

  this->element[0] *= temp;
  this->element[1] *= temp;
  this->element[2] *= temp;
  return *this;
}

vec_4f vec_4f::operator*(const double element_2)
{
  return vec_4f(this->element[0] * element_2, this->element[1] * element_2,
                this->element[2] * element_2);
}

vec_4f vec_4f::operator/(const double element_2)
{
  return vec_4f(this->element[0] / element_2, this->element[1] / element_2,
                this->element[2] / element_2);
}
double vec_4f::length() const
{
  return sqrt(this->element[0] * this->element[0] +
              this->element[1] * this->element[1] +
              this->element[2] * this->element[2]);
}

double vec_4f::squared_length() const
{
  return this->element[0] * this->element[0] +
         this->element[1] * this->element[1] +
         this->element[2] * this->element[2];
}

void vec_4f::makeUnitVector()

{
  double length = this->length();
  this->element[0] /= length;
  this->element[1] /= length;
  this->element[2] /= length;
}

vec_4f vec_4f::unitVector() const
{
  double length = this->length();
  return vec_4f(this->element[0] / length, this->element[1] / length,
                this->element[2] / length);
}

double vec_4f::dot(const vec_4f& vec2) const
{
  return this->element[0] * vec2[0] + this->element[1] * vec2[1] +
         this->element[2] * vec2[2];
}

vec_4f vec_4f::cross(const vec_4f& vec2) const
{
  return vec_4f((this->element[1] * vec2[2] - this->element[2] * vec2[1]),
                (-((this->element[0] * vec2[2]) - this->element[2] * vec2[0])),
                (this->element[0] * vec2[1] - this->element[1] * vec2[0]));
}
}  // namespace rtl

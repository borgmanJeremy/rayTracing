#include "ray.hpp"

namespace rtl
{
ray::ray(vec_4f const &origin, vec_4f const &direction)
{
  this->origin_vector = origin;
  this->direction_vector = direction;
}

vec_4f ray::getOrigin() const { return origin_vector; }
vec_4f ray::getDirection() const { return direction_vector; }

vec_4f ray::pointAtParameter(double t) const
{
  return this->getOrigin() + this->getDirection() * t;
}
}  // namespace rtl

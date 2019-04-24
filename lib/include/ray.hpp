#ifndef _RAY_HPP_
#define _RAY_HPP_
#include "vec_4f.hpp"

namespace rtl
{
class ray
{
 public:
  ray() {}
  ray(vec_4f const &origin, vec_4f const &direction);
  vec_4f getOrigin() const;
  vec_4f getDirection() const;
  vec_4f pointAtParameter(double t) const;

 private:
  vec_4f origin_vector;
  vec_4f direction_vector;
};
}  // namespace rtl
#endif  // _RAY_HPP_

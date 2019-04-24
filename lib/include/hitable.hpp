#ifndef _HITABLE_HPP_
#define _HITABLE_HPP_

#include "ray.hpp"
#include "vec_4f.hpp"

namespace rtl
{
class Material;

struct hitRecord
{
  double time;
  vec_4f pointVec;
  vec_4f normal;
  Material *materialPtr;
};
}  // namespace rtl

#endif  // _HITABLE_HPP_

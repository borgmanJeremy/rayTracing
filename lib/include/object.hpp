#ifndef _OBJECT_HPP_
#define _OBJECT_HPP_

#include <memory>
#include <random>
#include "hitable.hpp"
#include "material.hpp"
#include "ray.hpp"
#include "vec_4f.hpp"

namespace rtl
{
enum class ObjectType
{
  sphere,
  triangle
};

class Object
{
 public:
  virtual bool hit(ray const &incomingRay, double tMin, double tMax,
                   hitRecord &record) const = 0;

  virtual ~Object(){};

  std::unique_ptr<MaterialFactory> mat;
};

class SphereObject : public Object
{
 public:
  SphereObject(vec_4f centerInit, double radInit, MaterialType material);
  SphereObject(vec_4f centerInit, double radInit, MaterialType material,
               double idx);
  SphereObject(vec_4f centerInit, double radInit, MaterialType material,
               vec_4f alb);
  virtual bool hit(ray const &incomingRay, double tMin, double tMax,
                   hitRecord &record) const override;

 private:
  vec_4f center;
  double radius;
};
}  // namespace rtl
#endif  //_OBJECT_HPP_

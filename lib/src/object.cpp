#include "object.hpp"
namespace rtl
{
SphereObject::SphereObject(vec_4f centerInit, double radInit,
                           MaterialType material)
{
  this->center = centerInit;
  this->radius = radInit;
  this->mat = MaterialFactory::create(material);
}

SphereObject::SphereObject(vec_4f centerInit, double radInit,
                           MaterialType material, double idx)
{
  this->center = centerInit;
  this->radius = radInit;
  this->mat = MaterialFactory::create(material, idx);
}

SphereObject::SphereObject(vec_4f centerInit, double radInit,
                           MaterialType material, vec_4f alb)
{
  this->center = centerInit;
  this->radius = radInit;
  this->mat = MaterialFactory::create(material, alb);
}

bool SphereObject::hit(ray const &incomingRay, double tMin, double tMax,
                       hitRecord &record) const
{
  vec_4f originToCenter = incomingRay.getOrigin() - this->center;

  // look for roots in quadratic
  double a = incomingRay.getDirection().dot(incomingRay.getDirection());
  double b = originToCenter.dot(incomingRay.getDirection());
  double c = originToCenter.dot(originToCenter) - this->radius * this->radius;
  double discriminant = b * b - a * c;

  // record.materialPtr = this->mat;

  if (discriminant > 0)
  {
    double hitPoint = (-b - sqrt(b * b - a * c)) / a;
    if ((hitPoint < tMax) && (hitPoint > tMin))
    {
      record.time = hitPoint;
      record.pointVec = incomingRay.pointAtParameter(record.time);
      record.normal = (record.pointVec - this->center) / this->radius;

      return true;
    }

    hitPoint = (-b + sqrt(b * b - a * c)) / a;
    if ((hitPoint < tMax) && (hitPoint > tMin))
    {
      record.time = hitPoint;
      record.pointVec = incomingRay.pointAtParameter(record.time);
      record.normal = (record.pointVec - this->center) / this->radius;

      return true;
    }
  }

  return false;
}
}  // namespace rtl

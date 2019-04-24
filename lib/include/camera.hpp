#ifndef _CAMERA_HPP_
#define _CAMERA_HPP_

#include <cmath>
#include "ray.hpp"

namespace rtl
{
class Camera
{
 public:
  Camera();
  Camera(vec_4f lookFrom, vec_4f lookAt, vec_4f vUp, double vfov,
         double aspect);
  ray getRay(double s, double t);

 private:
  vec_4f origin;
  vec_4f lowerLeftCorner;
  vec_4f horizontal;
  vec_4f vertical;
};

Camera::Camera()
{
  Camera(vec_4f(0, 0, 0), vec_4f(0, 0, 0), vec_4f(0, 0, 0), 0, 0);
}

Camera::Camera(vec_4f lookFrom, vec_4f lookAt, vec_4f vUp, double vfov,
               double aspect)
{
  vec_4f u, v, w;

  double theta = vfov * 3.1415 / 180;
  double half_height = tan(theta / 2.0);
  double half_width = aspect * half_height;

  origin = lookFrom;
  w = (lookFrom - lookAt).unitVector();
  u = vUp.cross(w).unitVector();
  v = w.cross(u);

  lowerLeftCorner = origin - u * half_width - v * half_height - w;
  horizontal = u * 2 * half_width;
  vertical = v * 2 * half_height;
}

ray Camera::getRay(double s, double t)
{
  return ray(this->origin, this->lowerLeftCorner + this->horizontal * s +
                             this->vertical * t - origin);
}

}  // namespace rtl

#endif  //_CAMERA_HPP_

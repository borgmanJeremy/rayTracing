#ifndef _WORLD_HPP_
#define _WORLD_HPP_

#include <iostream>
#include <limits>
#include <random>
#include <thread>
#include <vector>
#include "camera.hpp"
#include "flat_image.hpp"
#include "hitable.hpp"
#include "object.hpp"
#include "ray.hpp"

namespace rtl
{
class World
{
 public:
  auto hitObject(ray const &incomingRay, double tMin, double tMax,
                 hitRecord &record) const;

  void adjustCamera(vec_4f lookFrom, vec_4f lookAt, vec_4f vUp, double vfov,
                    double aspect);

  void renderScene();
  void setImagePlane(unsigned int width, unsigned int height);
  void setOversample(unsigned int os);

  std::vector<std::unique_ptr<Object>> objectList;
  Camera camera;
  FlatImage imagePlane;

 private:
  vec_4f color(ray const &r, int depth);
  unsigned int oversample = 100;
};

void World::setOversample(unsigned int os) { this->oversample = os; }

void World::renderScene()
{
  std::random_device rand_device;
  std::mt19937 gen(rand_device());
  std::uniform_real_distribution<> dis(0.0, 1.0);

  ray camera_ray;
  vec_4f col;

  for (unsigned int i = 0; i < this->imagePlane.getHeight(); i++)
  {
    for (unsigned int j = 0; j < this->imagePlane.getWidth(); j++)
    {
      vec_4f temp_col;
      ray temp_ray;
      temp_col[0] = 0;
      temp_col[1] = 0;
      temp_col[2] = 0;

      for (unsigned int s = 0; s < this->oversample; s++)
      {
        double u = static_cast<double>(j + dis(gen)) /
                   static_cast<double>(this->imagePlane.getWidth());
        double v = static_cast<double>(i + dis(gen)) /
                   static_cast<double>(this->imagePlane.getHeight());

        temp_ray = this->camera.getRay(u, v);
        temp_col += color(temp_ray, 0);
      }

      temp_col /= static_cast<double>(this->oversample);

      this->imagePlane.imageMat[this->imagePlane.getHeight() - 1 - i][j].r =
        255.99 * temp_col.r();
      this->imagePlane.imageMat[this->imagePlane.getHeight() - 1 - i][j].g =
        255.99 * temp_col.g();
      this->imagePlane.imageMat[this->imagePlane.getHeight() - 1 - i][j].b =
        255.99 * temp_col.b();
    }
  }
}

void World::setImagePlane(unsigned int width, unsigned int height)
{
  this->imagePlane.setSize(width, height);
}

void World::adjustCamera(vec_4f lookFrom, vec_4f lookAt, vec_4f vUp,
                         double vfov, double aspect)
{
  this->camera = Camera(lookFrom, lookAt, vUp, vfov, aspect);
}

auto World::hitObject(ray const &incomingRay, double tMin, double tMax,
                      hitRecord &record) const
{
  hitRecord temp_rec;
  double closestSoFar = tMax;
  auto iter = this->objectList.end();

  for (unsigned int i = 0; i < this->objectList.size(); i++)
  {
    if (this->objectList[i]->hit(incomingRay, tMin, closestSoFar, temp_rec))
    {
      closestSoFar = temp_rec.time;
      record = temp_rec;
      iter = this->objectList.begin() + i;
    }
  }

  return iter;
}
vec_4f World::color(ray const &r, int depth)
{
  hitRecord rec;
  auto objectIter =
    this->hitObject(r, 0.001, std::numeric_limits<double>::max(), rec);
  if (objectIter != this->objectList.end())
  {
    ray scattered;
    vec_4f attenuation;

    auto rayScattered = objectIter->get()->mat.get()->scatterFactory(
      r, rec, attenuation, scattered);

    if (depth < 50 && rayScattered)
    {
      return attenuation * color(scattered, depth + 1);
    }
    else
    {
      return vec_4f(0, 0, 0);
    }
  }
  else
  {
    vec_4f unit_direction = r.getDirection().unitVector();
    double grad = 0.5 * (unit_direction.y() + 1);
    return vec_4f(1.0, 1.0, 1.0) * (1.0 - grad) +
           vec_4f(0.5, 0.7, 1.0) * (grad);
  }
}
}  // namespace rtl
#endif  //_WORLD_HPP_

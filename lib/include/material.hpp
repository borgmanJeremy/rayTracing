#ifndef _MATERIAL_HPP_
#define _MATERIAL_HPP_

#include <memory>
#include <random>
#include "hitable.hpp"
#include "material.hpp"
#include "ray.hpp"
#include "vec_4f.hpp"

namespace rtl
{
static std::random_device obj_rand_device;
static std::mt19937 obj_gen(obj_rand_device());
static std::uniform_real_distribution<> obj_dis(0.0, 1.0);

enum class MaterialType
{
  Metal,
  Dielectric,
  Lambertian
};

vec_4f randomVecInUnitSphereFactory();

vec_4f reflectFactory(vec_4f &v, vec_4f &n);

bool refractFactory(vec_4f const &v, vec_4f &n, double niOverNt,
                    vec_4f &refracted);

double schlickFactory(double cosine, double ref_idx);

class MaterialFactory
{
 public:
  static std::unique_ptr<MaterialFactory> create(MaterialType type, double idx);
  static std::unique_ptr<MaterialFactory> create(MaterialType type, vec_4f alb);
  static std::unique_ptr<MaterialFactory> create(MaterialType type);

  virtual bool scatterFactory(ray const &rayIn, hitRecord &record,
                              vec_4f &attenuation, ray &scattered) const = 0;
  virtual ~MaterialFactory(){};
};

class MetalMaterial : public MaterialFactory
{
 public:
  MetalMaterial() { this->albedo = vec_4f(0, 0, 0); }
  MetalMaterial(vec_4f alb) { this->albedo = alb; };
  virtual bool scatterFactory(ray const &rayIn, hitRecord &record,
                              vec_4f &attenuation,
                              ray &scattered) const override;

 private:
  vec_4f albedo;
};

class DielectricMaterial : public MaterialFactory
{
 public:
  DielectricMaterial() { this->ref_idx = 0; }
  DielectricMaterial(double idx) { this->ref_idx = idx; };

  virtual bool scatterFactory(ray const &rayIn, hitRecord &record,
                              vec_4f &attenuation,
                              ray &scattered) const override;

  void setMaterialProperty(double const idx);

 private:
  double ref_idx;
};
class LambertianMaterial : public MaterialFactory
{
 public:
  LambertianMaterial() { this->albedo = vec_4f(0, 0, 0); }
  LambertianMaterial(vec_4f alb) { this->albedo = alb; };
  virtual bool scatterFactory(ray const &rayIn, hitRecord &record,
                              vec_4f &attenuation,
                              ray &scattered) const override;

 private:
  vec_4f albedo;
};
}  // namespace rtl
#endif  // _MATERIAL_HPP_

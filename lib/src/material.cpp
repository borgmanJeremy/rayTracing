#include "material.hpp"

namespace rtl
{
vec_4f randomVecInUnitSphereFactory()
{
  vec_4f randVec;
  do
  {
    randVec =
      vec_4f(obj_dis(obj_gen), obj_dis(obj_gen), obj_dis(obj_gen)) * 2.0 -
      vec_4f(1, 1, 1);
  } while (randVec.squared_length() >= 1);
  return randVec;
}

vec_4f reflectFactory(vec_4f &v, vec_4f &n) { return v - n * v.dot(n) * 2.0; }

bool refractFactory(vec_4f const &v, vec_4f &n, double niOverNt,
                    vec_4f &refracted)
{
  vec_4f uv = v.unitVector();
  double dt = uv.dot(n);
  double discriminant = 1.0 - niOverNt * niOverNt * (1 - dt * dt);

  if (discriminant > 0)
  {
    refracted = (uv - n * dt) * niOverNt - n * sqrt(discriminant);
    return true;
  }
  else
  {
    return false;
  }
}

double schlickFactory(double cosine, double ref_idx)
{
  double r0 = (1 - ref_idx) / (1 + ref_idx);
  r0 = r0 * r0;
  return r0 + (1 - r0) * pow((1 - cosine), 5);
}

std::unique_ptr<MaterialFactory> MaterialFactory::create(MaterialType type)
{
  std::unique_ptr<MaterialFactory> pMaterial;

  switch (type)
  {
    case (MaterialType::Metal):
      pMaterial = std::make_unique<MetalMaterial>();
      return pMaterial;

    case (MaterialType::Dielectric):
      pMaterial = std::make_unique<DielectricMaterial>();
      return pMaterial;

    case (MaterialType::Lambertian):
      pMaterial = std::make_unique<LambertianMaterial>();
      return pMaterial;

    default:
      return nullptr;
  }
}

std::unique_ptr<MaterialFactory> MaterialFactory::create(MaterialType type,
                                                         vec_4f alb)
{
  std::unique_ptr<MaterialFactory> pMaterial;

  switch (type)
  {
    case (MaterialType::Metal):
      pMaterial = std::make_unique<MetalMaterial>(alb);
      return pMaterial;

    case (MaterialType::Dielectric):
      pMaterial = std::make_unique<DielectricMaterial>();
      return pMaterial;

    case (MaterialType::Lambertian):
      pMaterial = std::make_unique<LambertianMaterial>(alb);
      return pMaterial;

    default:
      return nullptr;
  }
}

std::unique_ptr<MaterialFactory> MaterialFactory::create(MaterialType type,
                                                         double idx)
{
  std::unique_ptr<MaterialFactory> pMaterial;

  switch (type)
  {
    case (MaterialType::Metal):
      pMaterial = std::make_unique<MetalMaterial>();
      return pMaterial;

    case (MaterialType::Dielectric):
      pMaterial = std::make_unique<DielectricMaterial>(idx);
      return pMaterial;

    case (MaterialType::Lambertian):
      pMaterial = std::make_unique<LambertianMaterial>();
      return pMaterial;

    default:
      return nullptr;
  }
}

void DielectricMaterial::setMaterialProperty(double const idx)
{
  this->ref_idx = idx;
}

bool LambertianMaterial::scatterFactory(ray const &rayIn, hitRecord &record,
                                        vec_4f &attenuation,
                                        ray &scattered) const
{
  vec_4f target =
    record.pointVec + record.normal + randomVecInUnitSphereFactory();
  scattered = ray(record.pointVec, target - record.pointVec);
  attenuation = this->albedo;
  return true;
}
bool DielectricMaterial::scatterFactory(ray const &rayIn, hitRecord &record,
                                        vec_4f &attenuation,
                                        ray &scattered) const
{
  vec_4f outwardNormal;
  vec_4f temp = rayIn.getDirection();
  vec_4f reflected = reflectFactory(temp, record.normal);
  double ni_over_nt;
  attenuation = vec_4f(1.0, 1.0, 1.0);
  vec_4f refracted;
  double reflect_prob;
  double cosine;

  if ((rayIn.getDirection().dot(record.normal)) > 0)
  {
    outwardNormal = -record.normal;
    ni_over_nt = ref_idx;
    cosine = ref_idx * rayIn.getDirection().dot(record.normal) /
             rayIn.getDirection().length();
  }

  else
  {
    outwardNormal = record.normal;
    ni_over_nt = 1.0 / ref_idx;
    cosine =
      -rayIn.getDirection().dot(record.normal) / rayIn.getDirection().length();
  }

  if (refractFactory(rayIn.getDirection(), outwardNormal, ni_over_nt,
                     refracted))
  {
    reflect_prob = schlickFactory(cosine, ref_idx);
  }

  else
  {
    scattered = ray(record.pointVec, reflected);
    reflect_prob = 1.0;
  }

  if (obj_dis(obj_gen) < reflect_prob)
  {
    scattered = ray(record.pointVec, reflected);
  }

  else
  {
    scattered = ray(record.pointVec, refracted);
  }
  return true;
}

bool MetalMaterial::scatterFactory(ray const &rayIn, hitRecord &record,
                                   vec_4f &attenuation, ray &scattered) const
{
  vec_4f temp = rayIn.getDirection().unitVector();
  vec_4f reflected = reflectFactory(temp, record.normal);
  scattered = ray(record.pointVec, reflected);
  attenuation = albedo;
  return ((scattered.getDirection().dot(record.normal) > 0));
}
}  // namespace rtl

#include <future>
#include <string>
#include <thread>
#include "../../lib/include/world.hpp"

std::unique_ptr<rtl::World> makeScene();
int main()
{
  unsigned int width{800};
  unsigned int height{600};
  std::vector<std::future<std::unique_ptr<rtl::World>>> vecFut;

  for (unsigned int i = 0; i < 10; i++)
  {
    std::future<std::unique_ptr<rtl::World>> fut = std::async(
      std::launch::deferred | std::launch::async, [height, width, i]() {
        auto scene = makeScene();

        scene->setImagePlane(width, height);
        scene->setOversample(1);

        scene->adjustCamera(rtl::vec_4f(0.0 + static_cast<double>(i) / 10.0, 1,
                                        1.0 + (static_cast<double>(i) / 10.0)),
                            rtl::vec_4f(0, 0, 0), rtl::vec_4f(0, 1, 0), 90,
                            double(width) / double(height));

        scene->renderScene();
        return scene;
      });
    vecFut.push_back(std::move(fut));
  }

  for (unsigned int i = 0; i < vecFut.size(); i++)
  {
    auto scene = vecFut[i].get();

    std::string fileName = "world" + std::to_string(i) + ".ppm";
    std::cout << "Wrote Frame: " << i << "/" << vecFut.size() << std::endl;
    scene->imagePlane.writePPM(fileName);
  }

  return 0;
}

std::unique_ptr<rtl::World> makeScene()
{
  auto scene = std::make_unique<rtl::World>();

  scene->objectList.push_back(std::make_unique<rtl::SphereObject>(
    rtl::vec_4f(0, 0, -1), 0.5, rtl::MaterialType::Lambertian,
    rtl::vec_4f(0.8, 0.3, 0.3)));

  scene->objectList.push_back(std::make_unique<rtl::SphereObject>(
    rtl::vec_4f(0, -100.5, -1), 100, rtl::MaterialType::Lambertian,
    rtl::vec_4f(0.5, 0.5, 0.5)));

  scene->objectList.push_back(std::make_unique<rtl::SphereObject>(
    rtl::vec_4f(-1, 0, -1), 0.5, rtl::MaterialType::Dielectric, 1.5));

  scene->objectList.push_back(std::make_unique<rtl::SphereObject>(
    rtl::vec_4f(-1, 0, -1), -0.45, rtl::MaterialType::Dielectric, 1.5));

  scene->objectList.push_back(std::make_unique<rtl::SphereObject>(
    rtl::vec_4f(1, 0, -1), 0.5, rtl::MaterialType::Metal,
    rtl::vec_4f(0.8, 0.6, 0.2)));

  return scene;
}

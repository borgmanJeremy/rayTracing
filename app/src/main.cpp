#include <fstream>
#include <iostream>
#include "flat_image.hpp"
int main()
{
  FlatImage testImage(600, 400);
  std::ofstream ppmFile;

  ppmFile.open("testppm.ppm");

  // Write PPM Header
  ppmFile << "P3\n";  // Write PPM Body
  auto imageWidth = 600;
  auto imageHeight = 400;

  ppmFile << imageWidth << " " << imageHeight << "\n";
  ppmFile << "255 \n";

  double r = 0;
  double g = 0;
  double b = 0;
  for (auto i = 0; i < imageHeight; i++)
  {
    for (auto j = 0; j < imageWidth; j++)
    {
      r = static_cast<double>(j) / imageWidth;
      g = static_cast<double>(i) / imageHeight;
      b = 0.1;
      ppmFile << static_cast<int>(r * 255) << " " << static_cast<int>(g * 255)
              << " " << static_cast<int>(b * 255) << "\n";
    }
  }
  ppmFile.close();
  return 0;
}


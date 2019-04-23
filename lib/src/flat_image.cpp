#include "flat_image.hpp"

FlatImage::FlatImage(unsigned int width, unsigned int height)
{
  this->imageMat.resize(width, std::vector<pixel>(height));

  this->height = height;
  this->width = width;
}

unsigned int FlatImage::getWidth() { return this->width; }
unsigned int FlatImage::getHeight() { return this->height; }

void FlatImage::writePPM(std::string fileName)
{
  std::ofstream ppmFile;
  ppmFile.open(fileName);

  ppmFile << "P3\n";
  ppmFile << this->width << " " << this->height << "\n";
  ppmFile << "255 \n";

  for (const auto i : this->imageMat)
  {
    for (const auto j : i)
    {
      ppmFile << static_cast<int>(j.r) << " ";
      ppmFile << static_cast<int>(j.g) << " ";
      ppmFile << static_cast<int>(j.b) << "\n";
    }
  }
  ppmFile.close();
}

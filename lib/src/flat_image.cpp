#include "flat_image.hpp"

namespace rtl
{
FlatImage::FlatImage(unsigned int width, unsigned int height)
{
  this->imageMat.resize(height, std::vector<pixel>(width));

  this->height = height;
  this->width = width;
}

unsigned int FlatImage::getWidth() const { return this->width; }
unsigned int FlatImage::getHeight() const { return this->height; }
void FlatImage::setSize(unsigned int width, unsigned int height)
{
  this->width = width;
  this->height = height;
  this->imageMat.resize(height, std::vector<pixel>(width));
}

void FlatImage::writePPM(const std::string& fileName)
{
  std::ofstream ppmFile;
  ppmFile.open(fileName);

  ppmFile << "P3\n";
  ppmFile << this->width << " " << this->height << "\n";
  ppmFile << "255 \n";

  for (const auto& i : this->imageMat)
  {
    for (const auto j : i)
    {
      ppmFile << static_cast<unsigned int>(j.r) << " ";
      ppmFile << static_cast<unsigned int>(j.g) << " ";
      ppmFile << static_cast<unsigned int>(j.b) << "\n";
    }
  }
  ppmFile.close();
}
}  // namespace rtl

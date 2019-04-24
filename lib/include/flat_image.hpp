#ifndef _FLAT_IMAGE_HPP_
#define _FLAT_IMAGE_HPP_

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

namespace rtl
{
typedef struct
{
  double r;
  double g;
  double b;
} pixel;

class FlatImage
{
 public:
  FlatImage() { FlatImage(0, 0); }
  FlatImage(unsigned int width, unsigned int height);

  unsigned int getWidth() const;
  unsigned int getHeight() const;

  void setSize(unsigned int width, unsigned int height);
  void writePPM(const std::string& fileName);

  std::vector<std::vector<pixel>> imageMat;

 private:
  unsigned int height;
  unsigned int width;
};
}  // namespace rtl

#endif  // _FLAT_IMAGE_HPP_

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

typedef struct
{
  unsigned int r;
  unsigned int g;
  unsigned int b;
} pixel;

class FlatImage
{
 public:
  FlatImage(unsigned int width, unsigned int height);

  unsigned int getWidth();
  unsigned int getHeight();

  void writePPM(std::string fileName);

 private:
  unsigned int height;
  unsigned int width;

  std::vector<std::vector<pixel>> imageMat;
};


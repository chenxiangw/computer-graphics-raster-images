#include "rgb_to_gray.h"

void rgb_to_gray(
    const std::vector<unsigned char> &rgb,
    const int width,
    const int height,
    std::vector<unsigned char> &gray)
{
  //Gray = (R*299 + G*587 + B*114 + 500) / 1000
  gray.resize(height * width);
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  ////////////////////////////////////////////////////////////////////////////
  for (size_t i = 0; i < height * width; i++)
  {
    gray[i] = (299 * rgb[3 * i] + 587 * rgb[3 * i + 1] + 114 * rgb[3 * i + 2]) / 1000;
  }
}

#include "rgba_to_rgb.h"

void rgba_to_rgb(
    const std::vector<unsigned char> &rgba,
    const int &width,
    const int &height,
    std::vector<unsigned char> &rgb)
{
  rgb.resize(height * width * 3);
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  ////////////////////////////////////////////////////////////////////////////
  for (size_t i = 0; i < height; i++)
  {
    for (size_t j = 0; j < width; j++)
    {
      rgb[3 * width * i + 3 * j] = rgba[4 * width * i + 4 * j];
      rgb[3 * width * i + 3 * j + 1] = rgba[4 * width * i + 4 * j + 1];
      rgb[3 * width * i + 3 * j + 2] = rgba[4 * width * i + 4 * j + 2];
    }
  }
}

#include "rotate.h"

void rotate(
    const std::vector<unsigned char> &input,
    const int width,
    const int height,
    const int num_channels,
    std::vector<unsigned char> &rotated)
{
  rotated.resize(height * width * num_channels);
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  ////////////////////////////////////////////////////////////////////////////
  for (size_t y = 0; y < height; y++)
  {
    for (size_t x = 0; x < width; x++)
    {
      rotated[3 * height * x + 3 * y] = input[3 * width * y + 3 * x];
      rotated[3 * height * x + 3 * y + 1] = input[3 * width * y + 3 * x + 1];
      rotated[3 * height * x + 3 * y + 2] = input[3 * width * y + 3 * x + 2];
    }
  }
}

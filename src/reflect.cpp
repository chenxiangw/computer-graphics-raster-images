#include "reflect.h"

void reflect(
    const std::vector<unsigned char> &input,
    const int width,
    const int height,
    const int num_channels,
    std::vector<unsigned char> &reflected)
{
  reflected.resize(width * height * num_channels);
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  ////////////////////////////////////////////////////////////////////////////
  for (size_t i = 0; i < height; i++)
  {
    for (size_t j = 0; j < width; j++)
    {
      reflected[3 * width * i + 3 * j] = input[3 * width * i + 3 * width - 3 - 3 * j];
      reflected[3 * width * i + 3 * j + 1] = input[3 * width * i + 3 * width - 2 - 3 * j];
      reflected[3 * width * i + 3 * j + 2] = input[3 * width * i + 3 * width - 1 - 3 * j];
    }
  }
}

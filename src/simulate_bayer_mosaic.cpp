#include "simulate_bayer_mosaic.h"

void simulate_bayer_mosaic(
    const std::vector<unsigned char> &rgb,
    const int &width,
    const int &height,
    std::vector<unsigned char> &bayer)
{
  bayer.resize(width * height);
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  ////////////////////////////////////////////////////////////////////////////
  for (size_t i = 0; i < height; i++)
  {
    for (size_t j = 0; j < width; j++)
    {
      if (i % 2 == 0 && j % 2 == 1)
      {
        //B
        bayer[width * i + j] = rgb[3 * width * i + 3 * j + 2];
      }
      else if (i % 2 == 1 && j % 2 == 0)
      {
        //R
        bayer[width * i + j] = rgb[3 * width * i + 3 * j];
      }
      else
      {
        //G
        bayer[width * i + j] = rgb[3 * width * i + 3 * j + 1];
      }
    }
  }
}

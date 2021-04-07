#include "demosaic.h"

void demosaic(
    const std::vector<unsigned char> &bayer,
    const int &width,
    const int &height,
    std::vector<unsigned char> &rgb)
{
  rgb.resize(width * height * 3);
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  ////////////////////////////////////////////////////////////////////////////
  //(0,0)
  rgb[0] = bayer[width];
  rgb[1] = bayer[0];
  rgb[2] = bayer[1];
  for (size_t j = 2; j < width - 1; j += 2)
  {
    //G (j,0)
    rgb[3 * j] = bayer[width + j];
    rgb[3 * j + 1] = bayer[j];
    rgb[3 * j + 2] = (bayer[j - 1] + bayer[j + 1]) / 2;
  }
  for (size_t j = 1; j < width - 1; j += 2)
  {
    //B (j,0)
    rgb[3 * j] = (bayer[width + j - 1] + bayer[width + j + 1]) / 2;
    rgb[3 * j + 1] = (bayer[j - 1] + bayer[j + 1] + bayer[width + j]) / 3;
    rgb[3 * j + 2] = bayer[j];
  }
  for (size_t i = 2; i < height - 1; i += 2)
  {
    //G (0,i)
    rgb[3 * width * i] = (bayer[width * (i - 1)] + bayer[width * (i + 1)]) / 2;
    rgb[3 * width * i + 1] = bayer[width * i];
    rgb[3 * width * i + 2] = bayer[width * i + 1];
  }
  for (size_t i = 1; i < height - 1; i += 2)
  {
    //R (0,i)
    rgb[3 * width * i] = bayer[width * i];
    rgb[3 * width * i + 1] = (bayer[width * (i - 1)] + bayer[width * (i + 1)] + bayer[width * i + 1]) / 3;
    rgb[3 * width * i + 2] = (bayer[width * (i - 1) + 1] + bayer[width * (i + 1) + 1]) / 2;
  }

  for (size_t i = 1; i < height - 1; i++)
  {
    for (size_t j = 1; j < width - 1; j++)
    {

      if (i % 2 == 0 && j % 2 == 0)
      {
        //G
        rgb[3 * width * i + 3 * j] = (bayer[width * (i - 1) + j] + bayer[width * (i + 1) + j]) / 2;
        rgb[3 * width * i + 3 * j + 1] = bayer[width * i + j];
        rgb[3 * width * i + 3 * j + 2] = (bayer[width * i + j - 1] + bayer[width * i + j + 1]) / 2;
      }
      else if (i % 2 == 0 && j % 2 == 1)
      {
        //B
        rgb[3 * width * i + 3 * j] = (bayer[width * (i - 1) + j - 1] + bayer[width * (i - 1) + j + 1] + bayer[width * (i + 1) + j - 1] + bayer[width * (i + 1) + j + 1]) / 4;
        rgb[3 * width * i + 3 * j + 1] = (bayer[width * i + j - 1] + bayer[width * i + j + 1] + bayer[width * (i + 1) + j] + bayer[width * (i - 1) + j]) / 4;
        rgb[3 * width * i + 3 * j + 2] = bayer[width * i + j];
      }
      else if (i % 2 == 1 && j % 2 == 0)
      {
        //R
        rgb[3 * width * i + 3 * j] = bayer[width * i + j];
        rgb[3 * width * i + 3 * j + 1] = (bayer[width * i + j - 1] + bayer[width * i + j + 1] + bayer[width * (i + 1) + j] + bayer[width * (i - 1) + j]) / 4;
        rgb[3 * width * i + 3 * j + 2] = (bayer[width * (i - 1) + j - 1] + bayer[width * (i - 1) + j + 1] + bayer[width * (i + 1) + j - 1] + bayer[width * (i + 1) + j + 1]) / 4;
      }
      else
      {
        //G
        rgb[3 * width * i + 3 * j] = (bayer[width * i + j - 1] + bayer[width * i + j + 1]) / 2;
        rgb[3 * width * i + 3 * j + 1] = bayer[width * i + j];
        rgb[3 * width * i + 3 * j + 2] = (bayer[width * (i - 1) + j] + bayer[width * (i + 1) + j]) / 2;
      }
    }
  }
}

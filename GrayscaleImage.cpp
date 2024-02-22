//----------------------------------------------------------
// CS162 Assignment Starter Code
// Copyright Andrew Scholer (ascholer@chemeketa.edu)
// Neither this code, nor any works derived from it
//    may be republished without approval.
//----------------------------------------------------------

#include <stdexcept>
#include <string>
using namespace std;

#include "GrayscaleImage.h"
GrayscaleImage::GrayscaleImage(int heightVal, int widthVal)
{
  height = heightVal;
  width = widthVal;

  pixels = new uint8_t[width * height];
  for (int i = 0; i < width * height; i++) {
    pixels[i] = 0;
  }
}
GrayscaleImage::~GrayscaleImage()
{
  delete[] pixels;
}
int GrayscaleImage::getWidth() const
{
  return width;
}

int GrayscaleImage::getHeight() const
{
  return height;
}

uint8_t GrayscaleImage::getPixel(int row, int col) const
{
  if (row >= height || row < 0 || col >= width || col < 0)
    throw out_of_range("Bad index in getPixel");
  return pixels[row * width + col];
}

void GrayscaleImage::setPixel(int row, int col, uint8_t brightness)
{
  if (row >= height || row < 0 || col >= width || col < 0)
    throw out_of_range("Bad index in setPixel");
  pixels[row * width + col] = brightness;
}

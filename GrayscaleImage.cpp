//----------------------------------------------------------
// CS162 Assignment Starter Code
// Copyright Andrew Scholer (ascholer@chemeketa.edu)
// Neither this code, nor any works derived from it
//    may be republished without approval.
//----------------------------------------------------------
/**
 * @brief Assignment 5
 * @name Yifei Zhao
 */
#include <iostream>
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
void GrayscaleImage::fill(uint8_t brightness)
{
  for (int i = 0; i < width * height; i++) {
    pixels[i] = brightness;
  }
}
string GrayscaleImage::toString() const
{
  // string desired = "0\t100\t0\t\n25\t0\t50\t\n";
  string returnString;
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      returnString += (to_string(getPixel(i, j)) + "\t");
    }
  }
  return returnString += "\n";
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

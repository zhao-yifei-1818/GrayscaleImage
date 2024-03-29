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
GrayscaleImage::GrayscaleImage(const GrayscaleImage& other)
{
  height = other.height;
  width = other.width;
  pixels = new uint8_t[width * height];
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      pixels[i * width + j] = (other.pixels[i * width + j]);
    }
  }
}

GrayscaleImage& GrayscaleImage::operator=(const GrayscaleImage& other)
{
  if (&other != this) {
    delete[] pixels;
    pixels = new uint8_t[other.width * other.height];
    this->height = other.height;
    this->width = other.width;
    for (int i = 0; i < height; i++) {
      for (int j = 0; j < width; j++) {
        pixels[i * width + j] = (other.pixels[i * width + j]);
      }
    }
  }
  return *this;
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
      returnString += (to_string(pixels[i * width + j]) + "\t");
    }
    returnString += "\n";
  }
  return returnString;
}
bool GrayscaleImage::operator==(const GrayscaleImage& other) const
{
  bool val1 = (height == other.height);
  bool val2 = (width == other.width);

  if (!val1 || !val2) {
    return false;
  }

  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      if (pixels[i * width + j] != other.pixels[i * width + j]) {
        return false;
      }
    }
  }
  return true;
}

GrayscaleImage::~GrayscaleImage()
{
  delete[] pixels;
}
GrayscaleImage GrayscaleImage::addFrame(int padding, uint8_t brightness) const
{
  GrayscaleImage temp(padding * 2 + height, padding * 2 + width);
  for (int i = 0; i < temp.height; i++) {
    for (int j = 0; j < temp.width; j++) {
      // this feels like centering a div in html
      if (i < padding || i >= padding + height || j < padding
          || j >= padding + width) {
        temp.pixels[i * temp.width + j] = brightness;
      } else {
        temp.pixels[i * temp.width + j] =
            pixels[(i - padding) * width + (j - padding)];
      }
    }
  }
  return temp;
}
GrayscaleImage GrayscaleImage::crop(int startRow, int startCol, int newHeight,
                                    int newWidth) const
{
  GrayscaleImage temp(newHeight, newWidth);

  if (startRow < 0 || startCol < 0 || startRow + newHeight > height
      || startCol + newWidth > width) {
    throw std::out_of_range("out of range"); // throw out of range
  }

  for (int i = 0; i < newHeight; i++) {
    for (int j = 0; j < newWidth; j++) {
      temp.pixels[i * newWidth + j] =
          pixels[(startRow + i) * width
                 + (startCol + j)]; // assigning at right starting place
    }
  }
  return temp;
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

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "canvas.hpp"
#include "stb_image_write.h"

#include <cmath>
#include <stdexcept>

// glad that we at computer graphics in college

Canvas::Canvas(int width, int height)
    : width(width), height(height), data(width * height * 3, 255) {}

// Bresenham's algorithm
void Canvas::drawLine(int x0, int y0, int x1, int y1, unsigned char r,
                      unsigned char g, unsigned char b) {
  int dx = std::abs(x1 - x0), sx = x0 < x1 ? 1 : -1;
  int dy = -std::abs(y1 - y0), sy = y0 < y1 ? 1 : -1;
  int err = dx + dy, e2;

  while (true) {
    setPixel(x0, y0, r, g, b);
    if (x0 == x1 && y0 == y1)
      break;
    e2 = 2 * err;
    if (e2 >= dy) {
      err += dy;
      x0 += sx;
    }
    if (e2 <= dx) {
      err += dx;
      y0 += sy;
    }
  }
}

void Canvas::drawArc(int cx, int cy, int radius, float start_angle,
                     float end_angle, unsigned char r, unsigned char g,
                     unsigned char b) {
  const float step = 1.0f / radius; // angle step ~1px resolution
  for (float theta = start_angle; theta <= end_angle; theta += step) {
    int x = static_cast<int>(cx + radius * std::cos(theta));
    int y = static_cast<int>(cy + radius * std::sin(theta));
    setPixel(x, y, r, g, b);
  }
}

void Canvas::drawCircle(int cx, int cy, int radius, unsigned char r,
                        unsigned char g, unsigned char b) {
  drawArc(cx, cy, radius, 0, 2 * M_PI, r, g, b);
}

void Canvas::save(const std::string &filename) {
  if (!stbi_write_png(filename.c_str(), width, height, 3, data.data(),
                      width * 3)) {
    throw std::runtime_error("Failed to write image.");
  }
}

void Canvas::setPixel(int x, int y, unsigned char r, unsigned char g,
                      unsigned char b) {
  if (x < 0 || x >= width || y < 0 || y >= height)
    return;
  int index = (y * width + x) * 3;
  data[index + 0] = r;
  data[index + 1] = g;
  data[index + 2] = b;
}

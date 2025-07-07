#ifndef smv_gpp_canvas_hpp
#define smv_gpp_canvas_hpp

#include <string>
#include <vector>

class Canvas {
public:
  Canvas(int width, int height);

  void drawLine(int x0, int y0, int x1, int y1, unsigned char r,
                unsigned char g, unsigned char b);

  void drawArc(int cx, int cy, int radius, float start_angle, float end_angle,
               unsigned char r, unsigned char g, unsigned char b);

  void drawCircle(int cx, int cy, int radius, unsigned char r, unsigned char g,
                  unsigned char b);

  void save(const std::string &filename);

private:
  int width, height;
  std::vector<unsigned char> data;

  void setPixel(int x, int y, unsigned char r, unsigned char g,
                unsigned char b);
};

#endif
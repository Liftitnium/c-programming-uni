#include <stdio.h>

typedef struct {
  int x;      ///< x-coordinate of the top-left corner
  int y;      ///< y-coordinate of the top-left corner
  int width;  ///< width of the rectangle
  int height; ///< height of the rectangle
} Rectangle;

int main() {
  Rectangle rect1; // Declare a variable of type Rectangle
  rect1.x = 10;
  rect1.y = 20;
  rect1.width = 100;
  rect1.height = 50;

  printf("Rectangle: x=%d, y=%d, width=%d, height=%d\n", rect1.x, rect1.y,
         rect1.width, rect1.height);
  return 0;
}
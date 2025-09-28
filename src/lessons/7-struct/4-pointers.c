#include <stdio.h>

typedef struct {
  int x;      ///< x-coordinate of the top-left corner
  int y;      ///< y-coordinate of the top-left corner
  int width;  ///< width of the rectangle
  int height; ///< height of the rectangle
} Rectangle;

void default_rectangle(Rectangle *rect) {
  rect->x = 0; // Use the -> operator to access members through a pointer
  rect->y = 0;
  rect->width = 100;
  rect->height = 50;
}

int main() {
  Rectangle rect1;           // Declare a variable of type Rectangle
  default_rectangle(&rect1); // Pass the address of rect1 to the function
  printf("Rectangle: x=%d, y=%d, width=%d, height=%d\n", rect1.x, rect1.y,
         rect1.width, rect1.height);
  return 0;
}
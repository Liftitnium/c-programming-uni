#include <stdio.h>

typedef struct {
  int x;      ///< x-coordinate of the top-left corner
  int y;      ///< y-coordinate of the top-left corner
  int width;  ///< width of the rectangle
  int height; ///< height of the rectangle
} Rectangle;

struct AValidStruct {
  int id;         ///< Unique identifier
  char name[50];  ///< Name of the entity
  Rectangle rect; ///< A Rectangle structure as a member
  float *data;    ///< Pointer to an array of float data
  int (*compute_area)(
      struct AValidStruct *); ///< Function pointer to compute area
};

int main() { return 0; }
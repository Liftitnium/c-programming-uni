#include <stdio.h>
#include <stdlib.h>

// Function to create a vector (array) with initial size
int *create_vector(size_t initial_size) {
  int *data = malloc(initial_size * sizeof(int));
  if (!data) {
    exit(EXIT_FAILURE);
  }
  return data;
}

// Function to resize the vector (array)
int *resize_vector(int *data, size_t new_size) {
  int *new_data = realloc(data, new_size * sizeof(int));
  if (!new_data) {
    free(data);
    exit(EXIT_FAILURE);
  }
  return new_data;
}
void print_vector(int *data, size_t size) {
  for (size_t i = 0; i < size; ++i)
    printf("%d ", data[i]);
  printf("\n");
}

int main() {
  size_t size = 5;
  int *vec = create_vector(size);
  for (size_t i = 0; i < size; ++i)
    vec[i] = (int)i;

  size_t new_size = 10;
  vec = resize_vector(vec, new_size);

  print_vector(vec, new_size);

  for (size_t i = size; i < new_size; ++i)
    vec[i] = (int)i;
  size = new_size;

  print_vector(vec, size);
  free(vec);
  return 0;
}

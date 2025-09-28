#include <stdio.h>
#include <time.h>

int main() {
  time_t now;            // Declare a variable of type time_t
  struct tm *local_time; // Declare a pointer to a struct tm
  time(&now);
  local_time = localtime(&now); // Convert to local time representation
  printf("Current date and time: %02d-%02d-%04d %02d:%02d:%02d\n",
         local_time->tm_mday,
         local_time->tm_mon + 1,     // Months are 0-11 in struct tm
         local_time->tm_year + 1900, // Years since 1900
         local_time->tm_hour, local_time->tm_min, local_time->tm_sec);
  return 0;
}
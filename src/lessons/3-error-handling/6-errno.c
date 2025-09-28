#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <stdbool.h>

int main(void) {
    errno = 0;
    long val = strtol("9999", NULL, 10);
    const bool is_error = errno != 0;
    if (is_error) {
        perror("Encountered the following error in strtol()");
        errno = 0; // We are responsible for resetting errno
    } else {
        printf("Value parsed: %ld\n", val);
    }
    return 0;
}

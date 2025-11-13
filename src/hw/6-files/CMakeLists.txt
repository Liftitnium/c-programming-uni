add_library(my_library library.c library.h)
add_executable(main main.c)
target_link_libraries(main PRIVATE my_library)



add_executable(main_th main.c)
# Link pthread library
target_link_libraries(main_th  pthread)
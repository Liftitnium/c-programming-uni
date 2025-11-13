add_executable(main_th main.c)
find_package(Threads REQUIRED)
target_link_libraries(main_th PRIVATE Threads::Threads)
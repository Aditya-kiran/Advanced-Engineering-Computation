add_library(glutil glutil.cpp glutil.h)
target_include_directories(glutil PUBLIC .)
target_link_libraries(glutil ysclass)


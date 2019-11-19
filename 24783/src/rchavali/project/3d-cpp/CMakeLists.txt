add_library(dha dha.h dha.cpp)
target_include_directories(dha PUBLIC .)
target_link_libraries(dha geblkernel)

add_executable(3d-cpp MACOSX_BUNDLE main.cpp glutil.cpp glutil.h)
target_link_libraries(3d-cpp fslazywindow geblkernel dha hiredis)


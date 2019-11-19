add_library(shootinggamelib shoot-3-class.cpp shoot-3-class.h)
target_link_libraries(shootinggamelib fssimplewindow ysglfontdata)
target_include_directories(shootinggamelib PUBLIC .)

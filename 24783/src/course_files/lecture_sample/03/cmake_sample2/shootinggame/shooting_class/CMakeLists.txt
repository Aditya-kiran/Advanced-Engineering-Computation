add_library(shootinggame_lib
shoot-3-class.cpp
shoot-3-class.h
)
target_include_directories(shootinggame_lib PUBLIC .)
target_link_libraries(shootinggame_lib ysglfontdata fssimplewindow)

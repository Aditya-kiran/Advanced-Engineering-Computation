add_library(simplebitmap 
	simplebitmap.cpp
	simplebitmap.h
	simplebitmaptemplate.h
	yspng.cpp
	yspng.h
	yspngenc.cpp
	yspngenc.h
)
target_include_directories(simplebitmap PUBLIC .)



add_executable(simplebitmaptest testmain.cpp)
target_link_libraries(simplebitmaptest simplebitmap)



add_executable(simplebitmapviewer MACOSX_BUNDLE viewer.cpp)
target_link_libraries(simplebitmapviewer simplebitmap fslazywindow)


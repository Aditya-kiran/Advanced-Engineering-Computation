add_library(stringParser parserClass.cpp parserClass.h)

add_library(Fgets 
	Fgets.cpp 
	Fgets.h
)

add_executable(main main.cpp)
target_link_libraries(main stringParser Fgets)

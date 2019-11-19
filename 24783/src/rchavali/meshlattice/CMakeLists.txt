add_library(meshlattice meshlattice.cpp meshlattice.h lattice.h)
target_include_directories(meshlattice PUBLIC .)
target_link_libraries(meshlattice ysclass geblkernel)



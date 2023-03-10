set(PROJECT_NAME ModernCompTec)
PROJECT(${PROJECT_NAME} C)
cmake_minimum_required(VERSION 3.4...3.20 FATAL_ERROR)
set(GSL_ROOT_DIR /home/onomylock/gsl/gsl-install)
set(GSL_INCLUDE_DIR /home/onomylock/gsl/gsl-install/include)
set(GSL_LIBRARY /home/onomylock/gsl/gsl-install/lib/libgsl.so)
set(GSL_CBLAS_LIBRARY /home/onomylock/gsl/gsl-install/lib/libgslcblas.so)

add_executable(${PROJECT_NAME}
	src/main.c
	src/Calculation/direct.h
	src/Calculation/direct.c
	src/View/ui.c
	src/View/ui.h
	src/Render/shader_program.c
	src/Render/shader_program.h
	#src/graph.c
	#src/graph.h
)

find_package (PkgConfig REQUIRED)
pkg_check_modules (GTK3 REQUIRED gtk+-3.0)
add_definitions (${GTK3_CFLAGS_OTHER})

include_directories (${GTK3_INCLUDE_DIRS})
link_directories (${GTK3_LIBRARY_DIRS})

target_link_libraries(${PROJECT_NAME} ${GTK3_LIBRARIES})

add_subdirectory(external/glad)
target_link_libraries(${PROJECT_NAME} glad)

add_custom_target(glade ALL
	COMMAND cmake -E copy_directory ${CMAKE_SOURCE_DIR}/glade ${CMAKE_BINARY_DIR}/glade
	DEPENDS ${MY_TARGET}
)

find_package(GSL REQUIRED)
target_link_libraries(${PROJECT_NAME} GSL::gsl GSL::gslcblas -lm)

target_link_options(${PROJECT_NAME} PRIVATE -rdynamic)



# add_subdirectory(glade)




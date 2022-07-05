# CMakeList.txt : CMake project for DesignPatterns, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)
project ("DesignPatterns")
set(CMAKE_CXX_STANDARD 17)

add_subdirectory("Factory")
add_subdirectory("Singleton")
add_subdirectory("AbstractFactory")


# Add source to this project's executable.
# add_executable (DesignPatterns  )

# TODO: Add tests and install targets if needed.

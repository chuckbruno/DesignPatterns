# CMakeList.txt : CMake project for DesignPatterns, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)
project ("DesignPatterns")
set(CMAKE_CXX_STANDARD 17)

add_subdirectory("Factory")
add_subdirectory("Singleton")
add_subdirectory("AbstractFactory")
add_subdirectory("ObjectPool")
add_subdirectory("Decorator")
add_subdirectory("Facade")
add_subdirectory("Adapter")
add_subdirectory("Adapter2")
add_subdirectory("Proxy")
add_subdirectory("Chain")
add_subdirectory("Composite")
add_subdirectory("State")
add_subdirectory("Controller")
add_subdirectory("Template")
# Add source to this project's executable.
# add_executable (DesignPatterns  )

# TODO: Add tests and install targets if needed.

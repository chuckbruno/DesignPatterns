cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
# Add source to this project's executable.
add_executable (template "main.cpp" "${CMAKE_SOURCE_DIR}/Utility/rand.h" "${CMAKE_SOURCE_DIR}/Utility/rand.cpp")
target_include_directories(template PRIVATE ${CMAKE_SOURCE_DIR}/Utility)
if(CMAKE_VERSION VERSION_GREATER 3.12)
	set_property(TARGET template PROPERTY CXX_STANDARD 20)
endif()
#if(CMAKE_VERSION VERSION_GREATER 3.12)
#set_property(TARGET Factory PROPERTY CXX_STANDARD 20)
#endif()
project(gerador)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=gnu++0x")
set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES gerador.cpp)
add_executable(gerador ${SOURCE_FILES})

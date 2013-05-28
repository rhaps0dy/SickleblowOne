cmake_minimum_required(VERSION 2.6)
project(SickleblowOne)

set(CMAKE_INSTALL_PREFIX /home/adria/cpp/SickleblowOne/dist)

if(UNIX)
link_directories(/usr/local/lib)
include_directories(/usr/local/include)
include_directories(/usr/local/include/OGRE)
include_directories(/usr/include/OIS)
include_directories(/usr/include/CEGUI)
add_definitions(-O0)
endif(UNIX)

add_subdirectory(src)

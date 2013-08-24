cmake_minimum_required(VERSION 2.8.11)
project(SickleblowOne)


if(UNIX)
set(CMAKE_INSTALL_PREFIX /home/adria/cpp/SickleblowOne/dist)

link_directories(/usr/local/lib)
link_directories(/usr/lib)
include_directories(/usr/local/include)
include_directories(/usr/include)
include_directories(/usr/local/include/OGRE)
include_directories(/usr/include/OGRE)
include_directories(/usr/include/OIS)
include_directories(/usr/include/CEGUI)
include_directories(/usr/local/include/chipmunk)
include_directories(/usr/include/chipmunk)
add_definitions(-O3 -g -std=c++11)

set(BOOST_SYSTEM boost_system)
endif(UNIX)


if(WIN32)
set(CMAKE_INSTALL_PREFIX C:/Users/adria/Dropbox/Sickleblow/Install_Windows) 

include_directories(C:/MinGW/include)
include_directories(C:/MinGW/include/OGRE)
include_directories(C:/MinGW/include/OIS)
link_directories(C:/MinGW/lib)
add_definitions(-O3 -std=c++11 -DRELEASE -DNO_LOGS)

set(BOOST_SYSTEM boost_system-mgw47-mt-1_51)
endif(WIN32)
add_subdirectory(src)

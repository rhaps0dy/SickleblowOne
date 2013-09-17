cmake_minimum_required(VERSION 2.8.11)
project(SickleblowOne)

#CXXFLAGS
set(CMAKE_CXX_FLAGS_DEBUG  "-g") 
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DRELEASE -DNO_LOGS") 
set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "-O3 -g")
add_definitions(-std=c++11)



#Boost libraries
set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
find_package(Boost REQUIRED COMPONENTS system)
include_directories(${Boost_INCLUDE_DIRS})

#OGRE and OIS
set(OGRE_CACHE_DIR "/usr/lib/OGRE/cmake" CACHE FILEPATH "Path of FindOGRE.cmake")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${OGRE_CACHE_DIR})

find_package(OGRE REQUIRED COMPONENTS OgreMain)
find_package(OIS REQUIRED)
include_directories(${OGRE_INCLUDE_DIRS} ${OIS_INCLUDE_DIRS})

#Chipmunk
set(CHIPMUNK_INCLUDE_DIRS "/usr/include/chipmunk" CACHE FILEPATH "Include directory for Chipmunk Physics Library")
set(CHIPMUNK_LIBRARIES "chipmunk")
include_directories(${CHIPMUNK_INCLUDE_DIRS})

####################################################################################

if(UNIX)
	set(CMAKE_BUILD_TYPE "RelWithDebInfo" CACHE STRING "Build type")
endif(UNIX)

if(WIN32)
	set(CMAKE_BUILD_TYPE "Release" CACHE STRING "Build type")
endif(WIN32)

add_subdirectory(src)

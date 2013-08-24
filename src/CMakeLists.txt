add_subdirectory(gamesetups)
add_subdirectory(interfaces)
add_subdirectory(configScripts)

#Interface.cpp no existeix, es nomes un .h!
add_library(skblcore SHARED ClassLoader.cpp GameSetup.cpp Player.cpp PPlayer.cpp Level.cpp PLevel.cpp LevelRenderer.cpp PlayerRenderer.cpp CameraMan.cpp)
target_compile_definitions(skblcore PRIVATE -DBUILDING_SKBLCORE)

add_executable(skbl clientMain.cpp)

if(UNIX)
target_link_libraries(skblcore OgreMain OIS dl chipmunk ${BOOST_SYSTEM})
target_link_libraries(skbl skblcore OgreMain OIS ${BOOST_SYSTEM})
endif(UNIX)
if(WIN32)
target_link_libraries(skblcore OgreMain OIS chipmunk ${BOOST_SYSTEM})
target_link_libraries(skbl skblcore OgreMain OIS ${BOOST_SYSTEM})
set_target_properties(skbl PROPERTIES LINK_FLAGS -Wl,--subsystem,windows)
endif(WIN32)

install(TARGETS skbl skblcore DESTINATION .)

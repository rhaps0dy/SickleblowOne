add_subdirectory(gamesetups)
add_subdirectory(interfaces)
add_subdirectory(configScripts)

#Interface.cpp no existeix, es nomes un .h!
add_library(skblcore SHARED ClassLoader.cpp GameSetup.cpp Player.cpp PPlayer.cpp Level.cpp PLevel.cpp LevelRenderer.cpp PlayerRenderer.cpp CameraMan.cpp PDebugger.cpp) 
target_compile_definitions(skblcore PRIVATE -DBUILDING_SKBLCORE)

add_executable(skbl clientMain.cpp)

target_link_libraries(skblcore ${OGRE_LIBRARIES} ${OIS_LIBRARIES} ${CHIPMUNK_LIBRARIES} ${Boost_LIBRARIES})
target_link_libraries(skbl skblcore ${OGRE_LIBRARIES} ${OIS_LIBRARIES} ${Boost_LIBRARIES})

if(WIN32)
set_target_properties(skbl PROPERTIES LINK_FLAGS -Wl,--subsystem,windows)
endif(WIN32)

install(TARGETS skbl skblcore DESTINATION .)

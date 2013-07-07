add_subdirectory(interfaces)
add_subdirectory(gamesetups)
add_subdirectory(configScripts)

#Interface.cpp no existeix, es nomes un .h!
add_executable(skbl ClassLoader.cpp GameSetup.cpp Player.cpp Level.cpp LevelRenderer.cpp PlayerRenderer.cpp CameraMan.cpp clientMain.cpp)

target_link_libraries(skbl OgreMain OIS dl boost_system)

install(TARGETS skbl DESTINATION .)

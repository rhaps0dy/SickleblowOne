add_subdirectory(interfaces)
add_subdirectory(gamesetups)
add_subdirectory(configScripts)

#Interface.cpp no existeix, es nomes un .h!
add_executable(SickleblowOneClient ClassLoader.cpp GameSetup.cpp Player.cpp Level.cpp clientMain.cpp)

target_link_libraries(SickleblowOneClient OgreMain OIS dl boost_system)

install(TARGETS SickleblowOneClient DESTINATION .)

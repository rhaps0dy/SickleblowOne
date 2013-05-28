add_subdirectory(interfaces)
add_subdirectory(gamesetups)
add_subdirectory(configScripts)

add_executable(SickleblowOneClient GameSetup.cpp Player.cpp clientMain.cpp)

target_link_libraries(SickleblowOneClient OgreMain OIS dl boost_system)

install(TARGETS SickleblowOneClient DESTINATION .)

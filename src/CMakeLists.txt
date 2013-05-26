add_executable(SickleblowOneClient clientMain.cpp GameSetup.cpp)

target_link_libraries(SickleblowOneClient OgreMain OIS)

install(TARGETS SickleblowOneClient DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/../../bin)

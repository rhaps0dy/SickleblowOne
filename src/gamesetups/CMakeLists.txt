set(CMAKE_EXE_LINKER_FLAGS -r)

add_library(GameSetupLocalProva SHARED GameSetupLocalProva.cpp)

target_link_libraries(GameSetupLocalProva OgreMain OIS)

install(TARGETS GameSetupLocalProva DESTINATION gamesetups)

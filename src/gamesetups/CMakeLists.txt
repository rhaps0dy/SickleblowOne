#set(CMAKE_EXE_LINKER_FLAGS -r)

add_library(GameSetupLocalProva SHARED GameSetupLocalProva.cpp)
target_compile_definitions(GameSetupLocalProva PRIVATE -DBUILDING_GAMESETUPLOCALPROVA)
target_link_libraries(GameSetupLocalProva skblcore)

install(TARGETS GameSetupLocalProva DESTINATION gamesetups)

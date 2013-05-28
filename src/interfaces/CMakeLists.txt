add_library(KeyboardInterface SHARED KeyboardInterface.cpp)

target_link_libraries(KeyboardInterface OIS)

install(TARGETS KeyboardInterface DESTINATION interfaces)


add_executable(main main.cpp)
target_link_libraries(main translate_into_turkish)
add_library(translate_into_turkish translate_into_turkish.cpp)
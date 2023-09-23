cmake_minimum_required(VERSION 3.15)

project(lab1)

# Включаем C++11 (или другую нужную версию)
set(CMAKE_CXX_STANDARD 11)

# Добавляем поддиректорию src, где находятся исходные файлы
add_subdirectory(src)

# Добавляем библиотеку Google Test
add_subdirectory(test)
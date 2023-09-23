# Исходные файлы для тестов
add_executable(translate_test translate_test.cpp)
target_include_directories(translate_test PRIVATE ../src)

# Связываем тесты с библиотеками
target_link_libraries(translate_test gtest gtest_main translate_into_turkish)

# Добавляем тесты
add_test(NAME translate_test COMMAND translate_test)
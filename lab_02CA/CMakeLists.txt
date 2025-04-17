# Минимальная версия CMake, необходимая для сборки
cmake_minimum_required(VERSION 3.10)

# Установка имени проекта
project(MyApp VERSION 1.0 LANGUAGES CXX)

# Указание стандарта C++
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Добавление исполняемого файла из ваших .cpp файлов
add_executable(MyApp main.cpp input.cpp interp.cpp interpolate3d.cpp spline.cpp)

# Если у вас есть заголовочные файлы, можно указать их для упрощения настройки
target_include_directories(MyApp PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

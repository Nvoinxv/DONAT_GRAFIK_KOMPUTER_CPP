cmake_minimum_required(VERSION 3.23)

project(DONAT_GRAFIKA VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${PROJECT_NAME}
    main.cpp
    src/matrix_rotasi.cpp
    src/membuat_geometris_donat.cpp
    src/render_ascii.cpp
    src/vektor_operasi.cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)
cmake_minimum_required(VERSION 3.0.0)
project(grokking VERSION 0.1.0 LANGUAGES C)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(DEFAULT_OUTPUT_DIR ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})

# find sources
file(GLOB_RECURSE sources_c ${CMAKE_CURRENT_LIST_DIR}/src/*.c)

foreach(filepath ${sources_c})
    file(RELATIVE_PATH relative_path "${CMAKE_CURRENT_LIST_DIR}/src/" "${filepath}")

    get_filename_component(filename ${filepath} NAME_WE)
    get_filename_component(relative_folder ${relative_path} DIRECTORY)

    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${DEFAULT_OUTPUT_DIR}/${relative_folder})
    add_executable("${filename}" "${filepath}")
endforeach()
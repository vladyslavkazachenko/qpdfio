cmake_minimum_required(VERSION 3.9.6)
project(qpdfio)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

enable_testing()
add_subdirectory(pdfio)

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
find_package(Qt4 REQUIRED)
include_directories(${QT_INCLUDES})

include_directories("${CMAKE_SOURCE_DIR}/src")

add_subdirectory(src/qpdfio/pdf1_0)
add_subdirectory(test/qpdfio/pdf1_0)

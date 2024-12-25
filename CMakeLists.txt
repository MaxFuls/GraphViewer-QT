cmake_minimum_required(VERSION 3.5)

project(Graph VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 REQUIRED COMPONENTS Widgets Gui)
find_package(Qt6 REQUIRED COMPONENTS Widgets Gui)

set(PROJECT_SOURCES main.cpp mainwindow.hpp mainwindow.cpp mainwindow.ui)
set(PROJECT_NAME Graph)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})

add_subdirectory(src/Graph)
add_subdirectory(src/Randomizer)
add_subdirectory(src/GraphBuilder)
add_subdirectory(src/GraphViewer)
add_subdirectory(src/DataWidget)
add_subdirectory(src/Form)

target_link_libraries(${PROJECT_NAME} PRIVATE GraphViewer GraphBuilder Randomizer GraphLib DataWidget Form Qt6::Gui)
target_include_directories(${PROJECT_NAME} PRIVATE src/GraphBuilder/include src/GraphViewer/include src/DataWidget/include)
 
# install(TARGETS Graph BUNDLE DESTINATION . LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

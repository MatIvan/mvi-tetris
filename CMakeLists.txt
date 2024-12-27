cmake_minimum_required(VERSION 3.14)


project(tetris
  LANGUAGES CXX
  VERSION 1.0.0
  DESCRIPTION "Simple tetris based on SFML"
)

# Options
set(THIRDPARTY_DIR "${CMAKE_SOURCE_DIR}/thirdparty" CACHE PATH "Dir for third party libraries")
set(SFML_USE_VERSION "3.0.0" CACHE STRING "Version of SFML library for search")

# Load thirdparty
include(${CMAKE_SOURCE_DIR}/cmake/PrepareSFML.cmake)


# Init project
add_executable(mvi-tetris
  BaseField.h BaseField.cpp
  BaseFigure.h BaseFigure.cpp
  FieldView.h FieldView.cpp
  FigureView.h FigureView.cpp
  NumericLabel.h NumericLabel.cpp
  NumericStorage.h NumericStorage.cpp
  TetrisController.h TetrisController.cpp
  TetrisView.h TetrisView.cpp
  main.cpp
)

target_link_libraries(mvi-tetris
  PRIVATE
    Thirdparty::SFML
)


install(
  FILES
    images/block16.png
    images/block16_gray.png
    images/leveltext.png
    images/numbers.png
    images/scoretext.png
  DESTINATION
    ./bin/images
)

install(TARGETS mvi-tetris RUNTIME DESTINATION)

include(CPack)

cmake_minimum_required(VERSION 3.19)
project(allegro)

set(CMAKE_CXX_STANDARD 11)


set(SOURCE_FILES main.cpp AllegroBase.cpp Shape.cpp Shape.h Rect.cpp Rect.h Circle.cpp Circle.h Square.cpp Square.h ScreenSaver.cpp ScreenSaver.h AlegroAppp.cpp AlegroAppp.h ShapeFactory.cpp ShapeFactory.h ControlablleSquare.cpp ControlablleSquare.h Velosity.cpp Velosity.h)
add_executable(Allegro ${SOURCE_FILES})


target_link_libraries (Allegro allegro allegro_primitives allegro_font )

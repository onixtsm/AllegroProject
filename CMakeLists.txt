cmake_minimum_required(VERSION 3.19)
project(allegro)

set(CMAKE_CXX_STANDARD 11)


set(SOURCE_FILES main.cpp Allegro/AllegroBase.cpp Shapes/Shape.cpp Shapes/Shape.h Shapes/Rect.cpp Shapes/Rect.h Shapes/Circle.cpp Shapes/Circle.h Shapes/Square.cpp Shapes/Square.h Allegro/ScreenSaver.cpp Allegro/ScreenSaver.h Allegro/AlegroAppp.cpp Allegro/AlegroAppp.h Factories/ShapeFactory.cpp Factories/ShapeFactory.h Shapes/ControlablleSquare.cpp Shapes/ControlablleSquare.h Helpers/Velosity.cpp Helpers/Velosity.h)
add_executable(Allegro ${SOURCE_FILES})


target_link_libraries (Allegro allegro allegro_primitives allegro_font )

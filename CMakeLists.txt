cmake_minimum_required(VERSION 3.19)
project(allegro)

set(CMAKE_CXX_STANDARD 11)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")
set(CMAKE_SYSTEM_NAME Windows)

set(CMAKE_C_COMPILER i686-w64-mingw32-gcc)
set(CMAKE_CXX_COMPILER i686-w64-mingw32-g++)
set(CMAKE_RC_COMPILER i686-w64-mingw32-windsetres)
set(CMAKE_RANLIB i686-w64-mingw32-ranlibset)
set(CMAKE_FIND_ROOT_PATH /usr/i686-w64-mingw32)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
set(CMAKE_SHARED_LIBRARY_LINK_CXX_FLAGS)

set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)

set(SOURCE_FILES main.cpp AllegroBase.cpp Shape.cpp Shape.h Rect.cpp Rect.h Circle.cpp Circle.h Square.cpp Square.h ScreenSaver.cpp ScreenSaver.h AlegroAppp.cpp AlegroAppp.h ShapeFactory.cpp ShapeFactory.h ControlablleSquare.cpp ControlablleSquare.h Vector.cpp Vector.h)
add_executable(Allegro ${SOURCE_FILES})


target_link_libraries (Allegro allegro allegro_primitives allegro_font )
target_link_libraries(Allegro -L/usr/include/allegro5/)
target_link_libraries(Allegro /usr/lib/liball*)
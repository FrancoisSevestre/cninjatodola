cmake_minimum_required(VERSION 3.10)

# set the project name
project(cninjatodola)

# set files variables
set(SRCS
  src/Application.cpp
  src/file.cpp
  src/ninjatodolalist.cpp
  src/variousfunctions.cpp
  src/command.cpp
  src/keyboardInput.cpp
  src/ninjatodolaobject.cpp
  src/Directory.cpp
  src/main.cpp
  src/tasklist.cpp
  src/externRepresentation.cpp
  src/NinjaTODOla.cpp
  src/test_zone.cpp
  )

set(HEADERS
  src/Application.hpp
  src/externRepresentation.hpp
  src/NinjaTODOla.hpp
  src/tasklist.hpp
  src/command.hpp
  src/file.hpp
  src/ninjatodolalist.hpp
  src/test_zone.hpp
  src/Directory.hpp
  src/keyboardInput.hpp
  src/ninjatodolaobject.hpp
  src/variousfunctions.hpp
  )

# add the executable
add_executable(cninjatodola ${SRCS} ${HEADERS})

# NinjaTODOla in C++! #
[![pipeline status](https://gitlab.com/FrancoisSevestre/cninjatodola/badges/master/pipeline.svg)](https://gitlab.com/FrancoisSevestre/cninjatodola/-/commits/master)

## 1. Descritpion ##
Ninjatodola is a TODO/mind mapping app with a lot of extra features, like bash and python commands in app execution or file browsing.


## 2. Build ##
### Linux ###
- Compile: 
`mkdir build && cd build && cmake .. && cmake --build .`
<br />or
`cd src && g++ -o cninjatodola Application.cpp command.cpp Directory.cpp externRepresentation.cpp file.cpp keyboardInput.cpp main.cpp NinjaTODOla.cpp ninjatodolalist.cpp ninjatodolaobject.cpp tasklist.cpp test_zone.cpp variousfunctions.cpp`
- Allow execution: 
`chmod u+x cninjatodola`
- Run: 
`./cninjatodola`

## 3. Usage ##

- Use the keyboard to append, explore and edit your task lists.
- Press h for help.

## 4. Docker ##
- Build the image:
`docker build -t cninjatodola-arch . `

- Run the image:
`docker run -ti cninjatodola-arch`
<br />or
`docker run -i -t registry.gitlab.com/francoissevestre/cninjatodola/cninjatodola-archlinux:latest` for pre-build image.



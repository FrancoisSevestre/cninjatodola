# NinjaTODOla in C++! #
## 1. Descritpion ##
Ninjatodola is a TODO/mind mapping app with a lot of extra features, like bash and python commands in app execution or file browsing.


## 2. Build ##
### Linux ###
- Compile: 
`g++ -o cninjatodola Application.cpp command.cpp Directory.cpp externRepresentation.cpp file.cpp keyboardInput.cpp main.cpp NinjaTODOla.cpp ninjatodolalist.cpp ninjatodolaobject.cpp tasklist.cpp test_zone.cpp variousfunctions.cpp`
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



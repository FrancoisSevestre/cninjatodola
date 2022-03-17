FROM archlinux:base-devel

RUN pacman -Syu --noconfirm

RUN mkdir /app

ADD . /app/

WORKDIR /app

RUN g++ -o cninjatodola Application.cpp command.cpp Directory.cpp externRepresentation.cpp file.cpp keyboardInput.cpp main.cpp NinjaTODOla.cpp ninjatodolalist.cpp ninjatodolaobject.cpp tasklist.cpp test_zone.cpp variousfunctions.cpp

RUN chmod u+x cninjatodola

CMD ./cninjatodola

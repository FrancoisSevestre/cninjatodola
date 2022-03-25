FROM archlinux:base-devel

RUN pacman -Syu --noconfirm

RUN mkdir /app

ADD . /app/

WORKDIR /app

RUN mkdir build && cd build && cmake .. && cmake --build .

RUN chmod u+x cninjatodola

CMD ./cninjatodola

FROM registry.gitlab.com/francoissevestre/dockerfiles/cmake

RUN mkdir /app

ADD . /app/

WORKDIR /app

RUN mkdir build && cd build && cmake .. && cmake --build .

RUN chmod u+x cninjatodola

CMD ./cninjatodola

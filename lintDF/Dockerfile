FROM archlinux:latest

RUN pacman -Syu --noconfirm

RUN mkdir /app

ADD . /app/

WORKDIR /app

RUN pacman -S python-pip --noconfirm && pip install cpplint

VOLUME /app/logs/

CMD cpplint * > logs/cpplint-report.log

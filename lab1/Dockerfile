FROM alpine
RUN apk update && apk add g++ git

WORKDIR /parvpo

RUN git clone https://github.com/vit6556/parvpo git
RUN cd git/lab1 && g++ -fopenmp -o lab1.out lab1.cpp
RUN mkdir results
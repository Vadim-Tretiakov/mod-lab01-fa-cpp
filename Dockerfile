# Повторяет .github/workflows/release.yml 
# Для запуска тестов на винде (обход ошибки phtreads lib)

FROM ubuntu:latest

RUN apt-get update 
RUN apt-get install --fix-missing -y \
    git \
    cmake \
    build-essential \
    libgtest-dev

COPY / /

RUN mkdir build && cd build && cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_CXX_FLAGS="-Werror" ..

RUN cd build && make

RUN /build/test/mod-lab01-fa-cpp.test

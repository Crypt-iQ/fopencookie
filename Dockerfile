FROM ubuntu:focal
COPY . /build
CMD chmod -R 777 /build && ./build/build.sh
#!bin/sh

mkdir -p bin

if command -v g++ >/dev/null 2>&1; then
    g++ ./src/*.cpp -o ./bin/main

else
    echo "g++ not found. Please install g++ on your package manager then try again"
    exit 1

fi
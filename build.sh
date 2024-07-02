#!/bin/sh

mkdir -p bin

if command -v g++ >/dev/null 2>&1; then
    g++ ./src/*.cpp -o ./bin/csc10004_SortingAlgo_unix_x86_64
    echo "Building complete"
else
    echo "g++ not found. Please install g++ on your package manager then try again"
    exit 1
fi

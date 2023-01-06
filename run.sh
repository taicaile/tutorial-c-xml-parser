#!/usr/bin/env bash

rm -rf build
mkdir -p build

cd build
cmake .. && make
cd ..

PROGRAM=./build/bin/test
if [ -f $PROGRAM ]; then
    echo "Run the program:"
    echo "----------------"
    $PROGRAM
else
    echo "No program generated."
fi

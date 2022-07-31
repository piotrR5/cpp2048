#!/bin/bash
echo compiling 2048.cpp
g++ -o 2048 2048.cpp -lncurses -lfmt
if test -f "2048"; then
    echo compiled succesfully
else
    echo compilation failed, check if required dependencies are installed with ./build_dependencies.sh
fi

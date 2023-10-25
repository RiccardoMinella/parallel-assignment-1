#! /bin/bash

# Compile and link the first C file
gcc array.c -o serial
if [ $? -eq 0 ]; then
  echo "Serial compilation was successful. Running serial..."
  ./serial
else
  echo "Compilation of array.c failed."
fi

# Compile and link the second C file
gcc -O3 -march=native array.c -o parallel
if [ $? -eq 0 ]; then
  echo "Parallel compilation was successful. Running parallel..."
  ./parallel
else
  echo "Compilation of array.c failed."
fi
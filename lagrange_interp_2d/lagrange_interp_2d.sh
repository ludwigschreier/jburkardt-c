#!/bin/bash
#
cp lagrange_interp_2d.h /$HOME/include
#
gcc -c -g -I /$HOME/include lagrange_interp_2d.c >& compiler.txt
if [ $? -ne 0 ]; then
  echo "Errors compiling lagrange_interp_2d.c"
  exit
fi
rm compiler.txt
#
mv lagrange_interp_2d.o ~/libc/$ARCH/lagrange_interp_2d.o
#
echo "Library installed as ~/libc/$ARCH/lagrange_interp_2d.o"

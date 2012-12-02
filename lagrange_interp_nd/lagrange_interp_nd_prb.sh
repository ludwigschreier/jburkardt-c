#!/bin/bash
#
gcc -c -g -I/$HOME/include lagrange_interp_nd_prb.c >& compiler.txt
if [ $? -ne 0 ]; then
  echo "Errors compiling lagrange_interp_nd_prb.c"
  exit
fi
rm compiler.txt
#
gcc lagrange_interp_nd_prb.o /$HOME/libc/$ARCH/lagrange_interp_nd.o \
                             /$HOME/libc/$ARCH/r8lib.o -lm
if [ $? -ne 0 ]; then
  echo "Errors linking and loading lagrange_interp_nd_prb.o."
  exit
fi
#
rm lagrange_interp_nd_prb.o
#
mv a.out lagrange_interp_nd_prb
./lagrange_interp_nd_prb > lagrange_interp_nd_prb_output.txt
if [ $? -ne 0 ]; then
  echo "Errors running lagrange_interp_nd_prb."
  exit
fi
rm lagrange_interp_nd_prb
#
echo "Program output written to lagrange_interp_nd_prb_output.txt"

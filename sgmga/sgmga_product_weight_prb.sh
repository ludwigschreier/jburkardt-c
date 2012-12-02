#!/bin/bash
#
gcc -c -g -I/$HOME/include sgmga_product_weight_prb.c >& compiler.txt
if [ $? -ne 0 ]; then
  echo "Errors compiling sgmga_product_weight_prb.c."
  exit
fi
rm compiler.txt
#
gcc sgmga_product_weight_prb.o /$HOME/libc/$ARCH/sgmga.o /$HOME/libc/$ARCH/sandia_rules.o -lm
if [ $? -ne 0 ]; then
  echo "Errors linking and loading sgmga_product_weight_prb.o."
  exit
fi
#
rm sgmga_product_weight_prb.o
#
mv a.out sgmga_product_weight_prb
./sgmga_product_weight_prb > sgmga_product_weight_prb_output.txt
if [ $? -ne 0 ]; then
  echo "Errors running sgmga_product_weight_prb."
  exit
fi
rm sgmga_product_weight_prb
#
echo "Program output written to sgmga_product_weight_prb_output.txt"

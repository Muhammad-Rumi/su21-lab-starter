#ifndef  LAB02_BIT_OPS_H_
#define  LAB02_BIT_OPS_H_

#include <stdio.h>
#include "bit_ops.c"  // NOLINT
unsigned get_bit(unsigned x, unsigned n);
void set_bit(unsigned * x, unsigned n, unsigned v);
void flip_bit(unsigned * x, unsigned n);
#endif  // LAB02_BIT_OPS_H_

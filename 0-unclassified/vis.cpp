#include <bits/stdc++.h>
#include "limits.h"

using namespace std;

float u2f(unsigned u) {
  union {
    unsigned u;
    float f;
  } a;
  a.u = u;
  return a.f;
}
unsigned f2u(float f) {
  union {
    unsigned u;
    float f;
  } a;
  a.f = f;
  return a.u;
}

unsigned test_float_half(unsigned uf) {
  float f = u2f(uf);
  float hf = 0.5*f;
  if (isnan(f))
    return uf;
  else
    return f2u(hf);
}

void print(unsigned a) {
    printf("%d ", a);
	for(int i = 31; i >= 0; i--) {
		if(i % 4 == 2) printf(" ");
		printf("%d", !!(a & (1 << i)));
	}
	printf("\n");
}

unsigned float_half(unsigned uf) {
	int frac = (1 << 23) - 1;
	int eksp = ((1 << 8) - 1) << 23;
	int one_eksp = (1 << 23);
	int clear_frac = (-1 ^ ((1 << 23) - 1));
	int msb = (1 << 31);
	int mmax = (1 << 31) - 1;
	
   unsigned temp = (uf & mmax);
   unsigned exp_part = (uf & eksp);
   unsigned sign_part = (uf & msb);
   if(exp_part == eksp) return uf;
   if(exp_part > one_eksp)
      temp -= one_eksp;
   else {
      temp = (temp >> 1) + ((temp & 3) == 3);
	}
   return (temp | sign_part);
}

void cek(unsigned a) {
    if (float_half(a) != test_float_half(a))
      print(a);
}

int main() {
    for (unsigned i = 0; i <= UINT_MAX; i++)
      cek(i);
		
	return 0;
}


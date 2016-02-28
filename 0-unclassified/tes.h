#include <bits/stdc++.h>

using namespace std;

unsigned float_half(unsigned uf) {
   unsigned temp = (uf & mmax);
   unsigned exp_part = (uf & eksp);
   unsigned sign_part = (uf & msb);
   if(exp_part == eksp) return uf;
   if(exp_part > one_eksp)
      temp -= one_eksp;
   else
      temp = (temp >> 1);
   return (temp | sign_part);
}

int main() {
	
	return 0;
}
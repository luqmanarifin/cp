#include <bits/stdc++.h>

using namespace std;

#define long long long

long p = (long) 2e9 + 89;
long a = 69;
long b = -857254909;
int k = 1000;

long p1[256], p2[256];

int main() {
  long pa, pb;
  while(~scanf("%I64d %I64d", &pa, &pb)) {
    long now = ((pa * pa % p * pa % p) + a * pa + b) % p;
    if(now < 0) now += p;
    assert(pb * pb % p == now);
    p1[pa / k] = pa;
    p2[pa / k] = pb;
  }
  for(int i = 0; i < 256; i++) {
    assert(p1[i] && p2[i]);
    if(p1[i] == 0 || p2[i] == 0) {
      printf("kentang %d\n", i);
    }
    //printf("%I64d %I64d\n", p1[i], p2[i]);
  }
  for(int i = 0; i < 256; i++) {
    printf("%I64d,", p1[i]);
  }
  printf("\n");
  for(int i = 0; i < 256; i++) {
    printf("%I64d,", p2[i]);
  }
  printf("\n");
  return 0;
}

#include <bits/stdc++.h>

using namespace std;

#define long long long

long p = (long) 2e9 + 89;

int main() {
  long a = 69;
  long b = -857254909;
  int k = 1000;
  
  long pa = 223001, pb = 862223667;
  
  long now = ((pa * pa % p * pa % p) + a * pa + b) % p;
  assert(pb * pb % p == now);
  return 0;
}

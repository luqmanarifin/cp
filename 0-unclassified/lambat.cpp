#include <bits/stdc++.h>

using namespace std;

#define long long long

long p = (long) 2e9 + 89;

long power(long a, long b) {
  if(b == 0) return 1;
  long temp = power(a, b / 2);
  temp = temp * temp % p;
  if(b & 1) temp = temp * a % p;
  return temp;
}

int main() {
  long a = 69;
  long b = -857254909;
  int k = 1000;
  long sip = (p - 1) / 2;
  int cari = 13513024;
  for(int i = cari; i <= cari; i++) {
    int from = i;
    int to = i + 1;
    bool found = false;
    for(long pa = from; pa < to && !found; pa++) {
      //printf("nyari %d di %I64d\n", i, pa);
      long now = ((pa * pa % p * pa % p) + a * pa + b) % p;
      if(now < 0) now += p;
      if(power(now, sip) != 1) continue;
      //cerr << "nyari " << i << " di " << pa << endl;
      for(long pb = 0; pb < p && !found; pb++) {
        if(pb * pb % p == now) {
          printf("%I64d %I64d\n", pa, pb);
          found = true;
        }
      }
    }
    if(!found) {
      cerr << "asu" << endl;
    }
  }
  return 0;
}


#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
const int lim = 100;

long long a[N];

int main() {
  long long n;
  int q;
  scanf("%lld %d", &n, &q);
  while (q--) {
    long long x;
    scanf("%lld", &x);
    //printf("NIKI TANYA %lld\n", x);
    x--;
    long long ada = n, st = 0;
    long long lompat = 2;
    bool found = 0;
    long long done = 0;
    
    int shift = 0;
    long long start = 0;
    while (ada > 0) {
      //printf("%lld %lld\n", ada, st);
      long long it = start + (st << shift);
      start += ((st ^ 1) << shift);
      //printf("starting from %lld\n", it);
      if (x >= it && x % lompat == it % lompat) {
        done += (x - it) / lompat + 1;
        found = 1;
        break;
      }
      
      long long take = ada / 2 + ((ada % 2) && (st == 0));
      st = (st ^ (ada % 2));
      ada -= take;
      done += take;
      lompat *= 2;
      shift++;
    }
    printf("%lld\n", done);
  }
  return 0;
}

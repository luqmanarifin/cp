#include <bits/stdc++.h>
 
using namespace std;
 
int cnt;
 
long long ask(int u, int v) {
  cnt++;
  if (cnt > 50) exit(0);
  printf("? %d %d\n", u, v);
  fflush(stdout);
  long long x;
  scanf("%lld", &x);
  return x;
}
 
void answer(long long n) {
  printf("! %lld\n", n);
  fflush(stdout);
}
 
int main() {
  for (int i = 2; ; i++) {
    long long u = ask(1, i);
    if (u == -1) {
      answer(i - 1);
      return 0;
    }
    long long v = ask(i, 1);
    if (u != v) {
      answer(u + v);
      return 0;
    }
  }
  return 0;
}

#include <bits/stdc++.h>

using namespace std;

int cnt;

long long ask(int u, int v) {
  cnt++;
  if (cnt > 50) assert(0);
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

int get_rand(int l, int r) {
  int len = r - l + 1;
  return rand() % len + l;
}

int main() {
  srand(time(NULL));
  for (int i = 2; ; i++) {
    int other = get_rand(1, i - 1);
    long long u = ask(other, i);
    if (u == -1) {
      answer(i - 1);
      return 0;
    }
    long long v = ask(i, other);
    if (u != v) {
      answer(u + v);
      return 0;
    }
  }
  return 0;
}

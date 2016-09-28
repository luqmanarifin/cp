#include <bits/stdc++.h>

using namespace std;

int d, k, n;

int add(int a, int b) {
  return (a + b) % d;
}

int subs(int a, int b) {
  return (((a - b) % d) + d) % d;
}

int pos(int at) {
  if (at % 2 != n % 2) {
    return add(at, n);
  } else {
    return subs(at, n);
  }
}

int main() {
  scanf("%d %d %d", &d, &k, &n);
  k--;
  int v;
  if (k % 2) {
    k = subs(k, n);
  } else {
    k = add(k, n);
  }
  printf("%d %d\n", pos(add(k, 1)) + 1, pos(subs(k, 1)) + 1);
  return 0;
}
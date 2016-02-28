#include <bits/stdc++.h>

using namespace std;

int b, p;
int ab;

void solve(int n) {
  if(n == 1) return;
  int g = __builtin_clz(n) ^ 31;
  int k = (1 << g);
  ab += k * b + k / 2;
  solve(n - k / 2);
}

int main() {
  int n;
  scanf("%d %d %d", &n, &b, &p);
  solve(n);
  printf("%d %d\n", ab, p * n);
  return 0;
}
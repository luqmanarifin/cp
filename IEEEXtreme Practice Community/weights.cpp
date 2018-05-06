
#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

int a[N];

int ask(int u, int v) {
  printf("Q 2 %d %d\n", u, v);
  fflush(stdout);
  int k;
  scanf("%d", &k);
  return k;
}

int main() {
  int n;
  scanf("%d", &n);

  int A = ask(1, 2);
  int B = ask(2, 3);
  int C = ask(1, 3);
  a[1] = (A - B + C) / 2;
  a[2] = A - a[1];
  a[3] = C - a[1];
  for (int i = 4; i <= n; i++) {
    int v = ask(1, i);
    a[i] = v - a[1];
  }
  printf("A");
  for (int i = 1; i <= n; i++) printf(" %d", a[i]);
  printf("\n");
  fflush(stdout);
  return 0;
}

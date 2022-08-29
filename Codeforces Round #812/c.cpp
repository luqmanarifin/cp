#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N], to[N];

void solve(int n) {
  // printf("solve %d\n", n);
  if (n <= 0) return;
  int rem = to[n - 1] - (n - 1);
  for (int i = rem; i < n; i++) {
    a[i] = to[n - 1] - i;
  }
  solve(rem);
}

int main() {
  for (int i = 0; i * i < N; i++) {
    int until = (i + 1) * (i + 1);
    to[i * i] = i * i;
    for (int j = i * i + 1; j < min(N, until); j++) {
      to[j] = until;
    }
  }

  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    solve(n);
    for (int i = 0; i < n; i++) {
      printf("%d%c", a[i], i == n - 1? '\n' : ' ');
    }
  }
  return 0;
}

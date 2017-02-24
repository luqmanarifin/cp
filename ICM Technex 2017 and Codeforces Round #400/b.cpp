#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

bool is[N];

int main() {
  for (int i = 2; i < N; i++) {
    if (!is[i]) {
      for (long long j = 1LL * i * i; j < N; j += i) {
        is[j] = 1;
      }
    }
  }
  int n;
  scanf("%d", &n);
  int ans = 1;
  if (n >= 3) {
    ans = 2;
  }
  printf("%d\n", ans);
  for (int i = 2; i <= n + 1; i++) {
    printf("%d ", is[i] + 1);
  }
  return 0;
}

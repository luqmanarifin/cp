#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

int ans[N];

int main() {
  for (int n = 2; n < N; n++) {
    bool ada = 0;
    for (int i = 2; i * i <= n; i++) {
      if (n % i == 0) {
        ans[n] += ans[i] * ans[n / i];
        ada = 1;
      } 
    }
    if (!ada) {
      ans[n] = 1;
    }
    printf("%d: %d\n", n, ans[n]);
  }

  return 0;
}

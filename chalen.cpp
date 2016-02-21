#include <bits/stdc++.h>

using namespace std;

long long c(int n, int k) {
  k = min(k, n - k);
  long long ret = 1;
  for(int i = 1; i <= k; i++) {
    ret = ret * (n - i + 1) / i;
  }
  return ret;
}

long long stars(int n, int k) {
  return c(n + k - 1, n);
}

int main() {
  int n;
  scanf("%d", &n);
  cout << stars(5, n) * stars(3, n) << endl;
  return 0;
}
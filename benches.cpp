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

int main() {
  int n;
  scanf("%d", &n);
  long long ans = c(n, 5);
  for(int i = 1; i <= 5; i++) {
    ans *= n - i + 1;
  }
  cout << ans << endl;
  return 0;
}
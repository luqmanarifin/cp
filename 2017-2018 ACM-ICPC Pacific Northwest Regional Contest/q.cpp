#include <bits/stdc++.h>

using namespace std;

long long sum(int n) {
  return 1LL * n * (n + 1) / 2;
}

int main() {
  int n;
  scanf("%d", &n);
  int l = 1, r = n;
  long long all = 1LL * n * (n - 1) / 2;
  long long x = (all + 1) / 2;
  while (l < r) {
    int mid = (l + r) >> 1;
    long long cur = sum(n - 1) - sum(n - 1 - mid);
    if (x <= cur) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  cout << l << endl;
  return 0;
}

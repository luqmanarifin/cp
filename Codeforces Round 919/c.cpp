#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int a[N];

vector<int> facs(int x) {
  vector<int> v;
  for (int i = 1; i * i <= x; i++) {
    if (x % i == 0) {
      if (i * i != x) {
        v.push_back(i);
        v.push_back(x / i);
      } else {
        v.push_back(i);
      }
    }
  }
  sort(v.begin(), v.end());
  return v;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", a + i);
    auto factors = facs(n);
    int ans = 0;
    for (auto len : factors) {
      int d = 0;
      for (int i = 0; i < len; i++) {
        int fpb = 0;
        for (int j = i; j < n; j += len) {
          if (j > i) {
            fpb = __gcd(fpb, abs(a[j] - a[j - len]));
          }
        }
        if (fpb > 0) {
          d = __gcd(d, fpb);
        }
      }
      if (d != 1) {
        ans++;
      }
    }
    printf("%d\n", ans);
  }

  return 0;
}

#include <bits/stdc++.h>

using namespace std;

const int N = 100;

int a[N];

long long power(long long a, long long b) {
  long long ret = 1;
  for (int i = 0; i < b; i++) ret *= a;
  return ret;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    int zero = 0, one = 0;
    for (int i = 0; i < n; i++) {
      int v;
      scanf("%d", &v);
      if (v == 0) {
        zero++;
      } else if (v == 1) {
        one++;
      }
    }
    printf("%lld\n", one * power(2, zero));
  }

  return 0;
}

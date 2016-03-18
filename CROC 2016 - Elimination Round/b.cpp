#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int bit[N], n, a[N];

void add(int i, int v) {
  for(; i <= n; i |= i + 1) {
    bit[i] += v;
  }
}

int find(int i) {
  int ret = 0;
  for(; i >= 0; i = (i & (i + 1)) - 1) {
    ret += bit[i];
  }
  return ret;
}

int main() {
  int k;
  scanf("%d %d", &n, &k);
  for(int i = 0; i < n; i++) a[i] = i;
  k = min(k, n / 2);
  for(int i = 0; i < k; i++) {
    swap(a[i], a[n - 1 - i]);
  }
  //for(int i = 0; i < n; i++) printf("%d ", a[i]); printf("\n");
  long long ans = 0;
  for(int i = 0; i < n; i++) {
    ans += find(n - a[i]);
    add(n - a[i], 1);
  }
  cout << ans << endl;
  return 0;
}

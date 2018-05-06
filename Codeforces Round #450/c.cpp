
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int bit[N];

void add(int i) {
  for (; i < N; i |= i + 1) bit[i]++;
}

int find(int i) {
  int ret = 0;
  for (; i >= 0; i = (i & (i + 1)) - 1) {
    ret += bit[i];
  }
  return ret;
}

int find(int l, int r) {
  return find(r) - find(l - 1);
}

int a[N], need[N], ok[N], r[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", a + i);
  for (int i = 1; i <= n; i++) {
    need[i] = find(a[i] + 1, n);
    if (need[i] == 0) {
      ok[i]++;
      r[i]++;
    }
    ok[i] += ok[i - 1];
    add(a[i]);
  }
  for (int i = n; i >= 1; i--) r[i] += r[i + 1];
  memset(bit, 0, sizeof(bit));
  
  int maxi = -1e9, ans = -1;
  for (int i = n; i >= 1; i--) {
    int now = find(1, a[i] - 1) + ok[i - 1] + r[i + 1];
    if (now > maxi) {
      maxi = now;
      ans = a[i];
    } else if (now == maxi && a[i] < ans) {
      ans = a[i];
    }
    if (need[i] == 1) add(a[i]);
  }
  cout << ans << endl;
  return 0;
}

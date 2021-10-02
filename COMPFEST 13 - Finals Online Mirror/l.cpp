#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int a[N];
int bit[N];
tuple<int, int, int> p[N];

int find(int i) {
  int ret = 0;
  for (; i >= 0; i = (i & (i + 1)) - 1) {
    ret = max(ret, bit[i]);
  }
  return ret;
}

void update(int i, int val) {
  for (; i < N; i |= i + 1) {
    bit[i] = max(bit[i], val);
  }
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
    p[i] = {i - a[i], i};
  }
  sort(p + 1, p + 1 + n);
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (p[i].first < 0) continue;
    int id = -p[i].second;
    int val = find(a[id]);
    update(a[id] + 1, val + 1);
    ans = max(ans, val + 1);
  }
  cout << ans << endl;
  return 0;
}

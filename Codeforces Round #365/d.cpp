#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

int bit[N];

void update(int i, int v) {
  for (; i >= 0; i = (i & (i + 1)) - 1) {
    bit[i] ^= v;
  }
}

int find(int i) {
  int ret = 0;
  for (; i < N; i |= i + 1) {
    ret ^= bit[i];
  }
  return ret;
}

int a[N], ans[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
  }
  int q;
  scanf("%d", &q);
  vector<tuple<int, int, int>> que;
  for (int i = 1; i <= q; i++) {
    int l, r;
    scanf("%d %d", &l, &r);
    que.emplace_back(r, l, i);
  }
  sort(que.begin(), que.end());
  map<int, int> last;
  int p = 0;
  for (int r = 1; r <= n; r++) {
    if (last.count(a[r])) {
      update(last[a[r]], a[r]);
    }
    while (p < que.size() && get<0>(que[p]) == r) {
      ans[get<2>(que[p])] = find(get<1>(que[p]));
      p++;
    }
    last[a[r]] = r;
  }
  for (int i = 1; i <= q; i++) printf("%d\n", ans[i]);
  return 0;
}

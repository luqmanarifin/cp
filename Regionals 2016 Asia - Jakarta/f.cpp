#include <bits/stdc++.h>

using namespace std;

const int N = 255;
const int BIG = 1e4 + 5;
const int M = 3e5 + 5;

int bit[N][N], a[N][N];

void upd(int i, int j, int val) {
  int t = j;
  for (; i < N; i |= i + 1) {
    for (j = t; j < N; j |= j + 1) {
      bit[i][j] += val;
    }
  }
}

int find(int i, int j) {
  int ret = 0, t = j;
  for (; i >= 0; i = (i & (i + 1)) - 1) {
    for (j = t; j >= 0; j = (j & (j + 1)) - 1) {
      ret += bit[i][j];
    }
  }
  return ret;
}

vector<pair<int, int>> pos[BIG];
int pt, r[M], c[M], s[M], k[M], ans[M];

void find(int lo, int hi, vector<int>& owner) {
  if (owner.empty()) return;
  int mid = (lo + hi) >> 1;
  while (pt < mid) {
    for (auto it : pos[pt+1]) {
      upd(it.first, it.second, +1);
    }
    pt++;
  }
  while (pt > mid) {
    for (auto it : pos[pt]) {
      upd(it.first, it.second, -1);
    }
    pt--;
  }
  vector<int> lef, rig;
  for (auto i : owner) {
    int cur = 0;
    cur += find(r[i] + s[i] - 1, c[i] + s[i] - 1);
    cur -= find(r[i] - 1, c[i] + s[i] - 1);
    cur -= find(r[i] + s[i] - 1, c[i] - 1);
    cur += find(r[i] - 1, c[i] - 1);
    if (cur < k[i]) {
      rig.push_back(i);
    } else {
      lef.push_back(i);
    }
    ans[i] = mid;
  }
  owner.clear();
  if (lo == hi) return;
  find(lo, mid, lef);
  find(mid + 1, hi, rig);
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      scanf("%d", &a[i][j]);
      pos[a[i][j]].emplace_back(i, j);
    }
  }
  int q;
  scanf("%d", &q);
  for (int i = 1; i <= q; i++) {
    scanf("%d %d %d %d", r + i, c + i, s + i, k + i); 
  }
  vector<int> owner;
  for (int i = 1; i <= q; i++) owner.push_back(i);
  find(1, 10000, owner);
  for (int i = 1; i <= q; i++) printf("%d\n", ans[i]);
  return 0;
}

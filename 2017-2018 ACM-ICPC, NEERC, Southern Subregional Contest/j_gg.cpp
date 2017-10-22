#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N], ma[N], b[N], p[N];
vector<int> q[N];

long long bit[N];

void add(int i, long long v) {
  for (; i < N; i |= i + 1) bit[i] += v;
}

long long find(int i) {
  long long ret = 0;
  for (; i >= 0; i = (i & (i + 1)) - 1) {
    ret += bit[i];
  }
  return ret;
}

set<int> masih;

void hapus(int at, int v) {
  //puts("wow");
  while (v) {
    auto it = masih.upper_bound(at);
    it--;
    int i = *it;
    int del = min(a[i], v);
    //printf("hapus %d di %d uppper %d sebanyak %d sisa %d\n", v, at, *it, del, a[i]);
    a[i] -= del;
    v -= del;
    add(i, -del);
    if (a[i] == 0) masih.erase(i);
  }
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) scanf("%d", a + i);
  for (int i = 0; i < m; i++) scanf("%d", b + i);
  for (int i = 0; i < m; i++) scanf("%d", p + i);
  ma[n - 1] = a[n - 1];
  for (int i = n - 2; i >= 0; i--) {
    ma[i] = max(ma[i + 1], a[i]);
  }
  // harga dan kemana
  vector<pair<int, int>> num;
  for (int i = 0; i < m; i++) {
    int l = 0, r = n - 1;
    while (l < r) {
      int mid = (l + r + 1) >> 1;
      if (ma[mid] >= b[i]) {
        l = mid;
      } else {
        r = mid - 1;
      }
    }
    if (ma[l] >= b[i]) {
      num.emplace_back(p[i], l);
      q[l].push_back(p[i]);
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++) add(i, a[i]);
  sort(num.begin(), num.end());
  for (int i = 0; i < n; i++) masih.insert(i);
  for (auto it : num) {
    int cost = it.first;
    int ke = it.second;
    int cur = find(ke);
    if (cur >= cost) {
      ans++;
      hapus(ke, cost);
    }
  }
  cout << ans << endl;
  return 0;
}
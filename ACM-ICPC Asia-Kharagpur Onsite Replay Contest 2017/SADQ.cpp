#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

#define ull unsigned long long

map<int, ull> mp[N];
vector<int> a[N];
vector<ull> s[N];

ull get(int at, int l, int r) {
  if (l > r) return 0;
  return s[at][r] - (l == 0? 0 : s[at][l-1]);
}

ull count(int l, int r) {
  if (l > r) return 0;
  return r - l + 1;
}

ull answer(int u, int v) {
  if (u > v) swap(u, v);
  if (mp[u].count(v)) return mp[u][v];
  //printf("answering %d %d\n", u, v);
  ull ret = 0;
  if (a[u].size() < a[v].size()) {
    for (auto it : a[u]) {
      int p = lower_bound(a[v].begin(), a[v].end(), it) - a[v].begin();
      ret += get(v, p, (int) a[v].size() - 1) - count(p, (int) a[v].size() - 1) * it;
      ret += count(0, p - 1) * it - get(v, 0, p - 1);
    }
  } else {
    for (auto it : a[v]) {
      int p = lower_bound(a[u].begin(), a[u].end(), it) - a[u].begin();
      ret += get(u, p, (int) a[u].size() - 1) - count(p, (int) a[u].size() - 1) * it;
      ret += count(0, p - 1) * it - get(u, 0, p - 1);
    }
  }
  return mp[u][v] = ret;
}

int main() {
  int k;
  scanf("%d", &k);
  for (int i = 1; i <= k; i++) {
    int sz;
    scanf("%d", &sz);
    while (sz--) {
      int v;
      scanf("%d", &v);
      a[i].push_back(v);
    }
    sort(a[i].begin(), a[i].end());
    for (int j = 0; j < a[i].size(); j++) {
      s[i].push_back(a[i][j]);
      if (j) {
        s[i][j] += s[i][j - 1];
      }
    }
  }
  
  //cout << get(1, 2, 3) << endl;
  
  int q;
  scanf("%d", &q);
  while (q--) {
    int l, r;
    scanf("%d %d", &l, &r);
    printf("%llu\n", answer(l, r));
  }
  return 0;
}

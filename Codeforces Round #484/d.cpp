#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int inf = 2e9;

int a[N];

int len[N];
set<pair<int, int>> s;    // panjang - start
set<int> start;

map<int, vector<int>> pos;

void insert(int p) {
  int l = p, r = p;
  auto it = start.lower_bound(p);
  if (it != start.end() && p + 1 == *it) {
    r = *it + len[*it] - 1;
    s.erase(make_pair(len[*it], *it));
    start.erase(it);
  }
  it = start.lower_bound(p);
  if (it != start.begin()) {
    it--;
    if (*it + len[*it] == p) {
      l = *it;
      s.erase(make_pair(len[*it], *it));
      start.erase(it);
    }
  }
  len[l] = r - l + 1;
  start.insert(l);
  s.insert(make_pair(len[l], l));
}

int main() {
  int n;
  scanf("%d", &n);
  set<int> all;
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
    pos[a[i]].push_back(i);
    all.insert(a[i]);
    all.insert(a[i] + 1);
  }
  int loc = 0, ans = inf;
  for (auto it : all) {
    int cur = s.size();
    bool ok = 1;
    if (!s.empty()) {
      auto b = s.begin();
      auto e = s.end();
      e--;
      if (b->first != e->first) {
        ok = 0;
      }
    }
    if (ok && cur > loc) {
      loc = cur;
      ans = it;
    }

    for (auto p : pos[it]) {
      insert(p);
    }
  }

  cout << ans << endl;

  return 0;
}

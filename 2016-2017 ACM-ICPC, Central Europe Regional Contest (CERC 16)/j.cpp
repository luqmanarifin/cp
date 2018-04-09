#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;
const long long inf = 1e18;

map<pair<int, int>, int> mp;
int a[N], num;

int get(int l, int r) {
  if (!mp.count(make_pair(l, r))) {
    mp[make_pair(l, r)] = num++;
  }
  return mp[{l, r}];
}

long long cost[N][4];
set<int> dq[N][2];

int main() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 4; j++) {
      cost[i][j] = inf;
    }
  }
  
  int n, d;
  scanf("%d %d", &n, &d);
  for (int i = 0; i < d; i++) scanf("%d", a + i);
  for (int i = 1; i < d; i++) {
    int l = min(a[i], a[i - 1]);
    int r = max(a[i], a[i - 1]);
    get(l, r);
  }
  int m;
  scanf("%d", &m);
  while (m--) {
    int u, v, p; char c;
    scanf("%d %d %c %d", &u, &v, &c, &p);
    int d;
    if (c == 'O') {
      d = 0;
    } else {
      d = 2;
    }
    if (u > v) {
      d ^= 1;
      swap(u, v);
    }
    int id = get(u, v);
    cost[id][d] = min(cost[id][d], 1LL * p);
  }
  for (int i = 1; i < d; i++) {
    int l = min(a[i], a[i - 1]);
    int r = max(a[i], a[i - 1]);
    int id = get(l, r);
    dq[id][a[i-1] > a[i]].insert(i);
  }
  long long ans = 0;
  for (int id = 0; id < num; id++) {
    //~ for (int j = 0; j < 4; j++) printf("%d %d: %lld\n", id, j, cost[id][j]);
    vector<pair<long long, int>> p;
    long long trip = min(cost[id][2], cost[id][0]) + min(cost[id][3], cost[id][1]);
    p.emplace_back(cost[id][2], 2);
    p.emplace_back(cost[id][3], 3);
    sort(p.begin(), p.end());
    for (auto it : p) {
      if (it.first >= trip) continue;
      int s = (it.second & 1);
      while (!dq[id][s].empty() && !dq[id][s ^ 1].empty()) {
        auto now = *(dq[id][s].begin());
        auto i = dq[id][s ^ 1].lower_bound(now);
        if (i != dq[id][s ^ 1].end()) {
          ans += it.first;
          dq[id][s].erase(now);
          dq[id][s ^ 1].erase(i);
        } else {
          break;
        }
      }
    }
    cost[id][0] = min(cost[id][0], cost[id][2]);
    cost[id][1] = min(cost[id][1], cost[id][3]);
    for (int j = 0; j < 2; j++) {
      ans += dq[id][j].size() * cost[id][j];
    }
  }
  cout << ans << endl;
  return 0;
}

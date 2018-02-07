#include <bits/stdc++.h>

using namespace std;

const int N = 5e4 + 5;

vector<pair<int, int>> edge[N];
int sub[N];
bool ok[N], alive[N];
int cnt[N];

void subtree(int now, int bef) {
  sub[now] = 1;
  for (auto it : edge[now]) {
    if (it.first == bef || !alive[it.first]) continue;
    subtree(it.first, now);
    sub[now] += sub[it.first];
  }
}

int find_center(int now, int bef, int sz) {
  for (auto it : edge[now]) {
    if (it.first == bef || !alive[it.first]) continue;
    if (sub[it.first] * 2 > sz) {
      return find_center(it.first, now, sz);
    }
  }
  return now;
}

// return 1 if ok, 0 if not
int dfs_1(int now, int bef, int last) {
  bool ret = 1;
  for (auto it : edge[now]) {
    if (it.first == bef || !alive[it.first]) continue;
    ret &= (last != it.second);
    ret &= dfs_1(it.first, now, it.second);
  }
  return ret;
}

void dfs_2(int now, int bef, int last, int carry) {
  ok[now] &= carry;
  for (auto it : edge[now]) {
    if (it.first == bef || !alive[it.first]) continue;
    dfs_2(it.first, now, it.second, carry && last != it.second);
  }
}

void centroid(int now) {
  subtree(now, -1);
  now = find_center(now, -1, sub[now]);
  //printf("center %d\n", now);
  vector<tuple<int, int, int>> adj;   // node, last, ok atau nggak
  int child_ok = 0;
  for (auto it : edge[now]) {
    if (!alive[it.first]) continue;
    int ret = dfs_1(it.first, now, it.second);
    //printf("adj %d %d %d\n",it.first, it.second, ret);
    adj.emplace_back(it.first, it.second, ret);
    child_ok += ret;
    cnt[it.second]++;
  }
  if (child_ok != adj.size()) {
    ok[now] = 0;
  }
  for (auto it : adj) {
    int node, last, okk;
    tie(node, last, okk) = it;
    int carry = (cnt[last] == 1 && child_ok - okk + 1 == adj.size());
    dfs_2(node, now, last, carry);
  }
  for (auto it : adj) {
    int last;
    tie(ignore, last, ignore) = it;
    cnt[last]--;
  }
  alive[now] = 0;
  for (auto it : adj) {
    int node;
    tie(node, ignore, ignore) = it;
    centroid(node);
  }
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    edge[a].emplace_back(b, c);
    edge[b].emplace_back(a, c);
  }
  for (int i = 1; i <= n; i++) ok[i] = alive[i] = 1;
  centroid(1);
  vector<int> ans;
  for (int i = 1; i <= n; i++) if (ok[i]) ans.push_back(i);
  printf("%d\n", ans.size());
  for (auto it : ans) printf("%d\n", it);
  return 0;
}

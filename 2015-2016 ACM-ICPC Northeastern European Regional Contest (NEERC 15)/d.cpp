#include <bits/stdc++.h>

using namespace std;

const string NAME = "distance";

const int N = 1e5 + 5;

set<int> edge[N];
pair<int, int> edges[N];
set<int> where[N];

vector<pair<int, int>> ask[N];
int ans[N], n, d[N][2];

bool between(int v, int l, int r) {
  auto it = where[v].lower_bound(l);
  return it != where[v].end() && *it <= r;
}

bool valid(int i) {
  return 1 <= i && i <= n - 3;
}

void solve(int l, int r) {
  if (l + 1 == r) {
    set<int> all;
    all.insert(edges[l].first);
    all.insert(edges[l].second);
    all.insert(edges[r].first);
    all.insert(edges[r].second);
    for (auto i : all) {
      for (auto q : ask[i]) {
        if (between(q.first, l, r)) {
          int cur = (i != q.first);
          //printf("%d %d %d\n", i, q.first, cur);
          ans[q.second] = min(ans[q.second], cur);
        }
      }
    }
    return;
  }
  int mid = (l + r) >> 1;
  set<int> nodes;
  nodes.insert(edges[mid].first);
  nodes.insert(edges[mid].second);
  
  queue<int> q;
  q.push(edges[mid].first);
  d[edges[mid].first][0] = 0;
  while (!q.empty()) {
    int now = q.front();
    q.pop();
    
    int near = (now + 1) % n;
    if (between(near, l, r) && d[near][0] == -1) {
      d[near][0] = d[now][0] + 1;
      q.push(near);
      nodes.insert(near);
    }
    
    near = (now + n - 1) % n;
    if (between(near, l, r) && d[near][0] == -1) {
      d[near][0] = d[now][0] + 1;
      q.push(near);
      nodes.insert(near);
    }
    
    for (auto near : edge[now]) {
      if (between(near, l, r) && d[near][0] == -1) {
        d[near][0] = d[now][0] + 1;
        q.push(near);
        nodes.insert(near);
      }
    }
  }
  
  q.push(edges[mid].second);
  d[edges[mid].second][1] = 0;
  while (!q.empty()) {
    int now = q.front();
    q.pop();
    
    int near = (now + 1) % n;
    if (between(near, l, r) && d[near][1] == -1) {
      d[near][1] = d[now][1] + 1;
      q.push(near);
      nodes.insert(near);
    }
    
    near = (now + n - 1) % n;
    if (between(near, l, r) && d[near][1] == -1) {
      d[near][1] = d[now][1] + 1;
      q.push(near);
      nodes.insert(near);
    }
    
    for (auto near : edge[now]) {
      if (between(near, l, r) && d[near][1] == -1) {
        d[near][1] = d[now][1] + 1;
        q.push(near);
        nodes.insert(near);
      }
    }
  }
  
  for (auto i : nodes) {
    for (auto q : ask[i]) {
      int j = q.first;
      int id = q.second;
      if (nodes.count(j)) {
        ans[id] = min(ans[id], d[i][0] + d[j][0]);
        ans[id] = min(ans[id], d[i][1] + d[j][1]);
        ans[id] = min(ans[id], d[i][0] + d[j][1] + 1);
        ans[id] = min(ans[id], d[i][1] + d[j][0] + 1);
      }
    }
  }
  for (auto it : nodes) d[it][0] = d[it][1] = -1;
  
  solve(l, mid);
  solve(mid, r);
}

int main() {
  freopen((NAME + ".in").c_str(), "r", stdin);
  freopen((NAME + ".out").c_str(), "w", stdout);
  
  scanf("%d", &n);
  for (int i = 0; i < n - 3; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    u--; v--;
    edge[u].insert(v);
    edge[v].insert(u);
  }
  int p, q;
  for (int i = 0; i < n; i++) {
    for (auto it : edge[i]) {
      if (it == (i + 2) % n) {
        p = i;
        q = it;
        goto START;
      }
    }
  }
  START:;
  where[(p+1)%n].insert(0);
  edges[0] = {(p+1)%n, (p+1)%n};
  for (int i = 1; i <= n - 3; i++) {
    //printf("p q %d %d\n", p, q);
    edges[i] = {p, q};
    where[p].insert(i);
    where[q].insert(i);
    if (edge[p].count((q + 1) % n)) {
      q = (q + 1) % n;
    } else {
      p = (p + n - 1) % n;
    }
  }
  where[(q+1)%n].insert(n - 2);
  edges[n - 2] = {(q+1)%n, (q+1)%n};
  
  fill(ans, ans + N, N);
  scanf("%d", &q);
  for (int i = 0; i < q; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    u--; v--;
    ask[u].emplace_back(v, i);
    ask[v].emplace_back(u, i);
  }
  memset(d, -1, sizeof(d));
  solve(0, n - 2);
  for (int i = 0; i < q; i++) printf("%d\n", ans[i]);
 
  fclose(stdin);
  fclose(stdout);
  return 0;
}

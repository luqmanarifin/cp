#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const long long inf = 1e15;

vector<pair<int, int>> edge[N];
vector<pair<int, int>> back[N];
int a[N], b[N], l[N];
int ada[N], bda[N];
long long from[N], to[N];
int ta[N], tb[N];

int main() {
  int n, m, s, t;
  scanf("%d %d %d %d", &n, &m, &s, &t);
  for(int i = 0; i < m; i++) {
    scanf("%d %d %d", a + i, b + i, l + i);
    edge[a[i]].emplace_back(b[i], l[i]);
    back[b[i]].emplace_back(a[i], l[i]);
  }
  
  // ASU
  long long lower = -1, upper = -1;
  
  for(int i = 0; i < N; i++) {
    from[i] = to[i] = inf;
  }
  priority_queue<pair<long long, int>> pq;
  pq.emplace(0, s);
  from[s] = 0;
  while(!pq.empty()) {
    long long cost; int now;
    tie(cost, now) = pq.top();
    cost = -cost;
    pq.pop();
    if(from[now] != cost) continue;
    for(auto it : edge[now]) {
      long long ncos = cost + it.second;
      int near = it.first;
      if(ncos < from[near]) {
        from[near] = ncos;
        pq.emplace(-ncos, near);
        ada[near] = 1;
        ta[near] = now;
      } else if(ncos == from[near]) {
        ada[near]++;
      }
    }
  }
  int dfs = t;
  while(dfs != s) {
    if(ada[dfs] > 1) {
      break;
    }
    dfs = ta[dfs];
  }
  if(ada[dfs] > 1) upper = from[dfs];
  
  assert(pq.empty());
  pq.emplace(0, t);
  to[t] = 0;
  while(!pq.empty()) {
    long long cost; int now;
    tie(cost, now) = pq.top();
    cost = -cost;
    pq.pop();
    if(to[now] != cost) continue;
    for(auto it : back[now]) {
      long long ncos = cost + it.second;
      int near = it.first;
      if(ncos < to[near]) {
        to[near] = ncos;
        pq.emplace(-ncos, near);
        bda[near] = 1;
        tb[near] = now;
      } else if(ncos == to[near]) {
        bda[near]++;
      }
    }
  }
  dfs = s;
  while(dfs != t) {
    if(bda[dfs] > 1) {
      break;
    }
    dfs = tb[dfs];
  }
  if(bda[dfs] > 1) lower = from[dfs];
  
  long long best = from[t];
  assert(from[t] == to[s]);
  //printf("OLWER UPPER %I64d %I64d\n", lower, upper);
  for(int i = 0; i < m; i++) {
    if(from[a[i]] + to[b[i]] + l[i] == best && ada[b[i]] == 1 && bda[a[i]] == 1 && !(lower < from[b[i]] && from[b[i]] < upper)) {
      puts("YES");
    } else if(from[a[i]] + to[b[i]] + 1 < best) {
      printf("CAN %I64d\n", l[i] - (best - 1 - from[a[i]] - to[b[i]]));
    } else {
      puts("NO");
    }
  }
  return 0;
}

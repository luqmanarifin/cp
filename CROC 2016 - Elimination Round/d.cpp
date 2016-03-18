#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int to[N], u[N], v[N];
vector<int> edge[N];
int aft[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for(int i = 0; i < m; i++) {
    scanf("%d %d", &u[i], &v[i]);
    to[v[i]]++;
    edge[u[i]].push_back(v[i]);
  }
  vector<int> topo;
  queue<int> q;
  for(int i = 1; i <= n; i++) {
    if(to[i] == 0) {
      q.push(i);
    }
  }
  while(!q.empty()) {
    if(q.size() != 1) {
      puts("-1");
      return 0;
    }
    int now = q.front();
    q.pop();
    topo.push_back(now);
    for(auto it : edge[now]) {
      to[it]--;
      if(to[it] == 0) {
        q.push(it);
      }
    }
  }
  //puts("topo done");
  //printf("%d\n", topo.size());
  if(topo.size() != n) {
    puts("-1");
    return 0;
  }
  for(int i = 0; i + 1 < topo.size(); i++) {
    aft[topo[i]] = topo[i + 1];
  }
  for(int i = m - 1; i >= 0; i--) {
    if(aft[u[i]] == v[i]) {
      printf("%d\n", i + 1);
      return 0;
    }
  }
  assert(false);
  return 0;
}

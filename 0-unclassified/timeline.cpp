#include <bits/stdc++.h>

using namespace std;

const int N = 1005;
const int inf = 1e9;

int f[N];
int d[N];
vector<int> edge[N], back[N];
int cost[N], low[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; i++) {
    scanf("%d", d + i);
  }
  while(m--) {
    int a, b;
    scanf("%d %d", &a, &b);
    edge[a].push_back(b);
    back[b].push_back(a);
    f[b]++;
  }
  stack<int> topo;
  for(int i = 0; i < n; i++) {
    if(f[i] == 0) {
      topo.push(i);
    }
  }
  int vis = 0;
  while(!topo.empty()) {
    int now = topo.top();
    vis++;
    topo.pop();
    for(int i = 0; i < edge[now].size(); i++) {
      int it = edge[now][i];
      f[it]--;
      if(f[it] == 0) {
        topo.push(it);
      }
      cost[it] = max(cost[it], cost[now] + d[now]);
    }
  }
  /*
  assert(vis == n);
  if(vis != n) {
    puts("Tidak Ada Waktu");
    return 0;
  }
  */
  int all_done = -1;
  for(int i = 0; i < n; i++) {
    all_done = max(all_done, cost[i] + d[i]);
  }
  
  for(int i = 0; i < n; i++) {
    f[i] = edge[i].size();
    low[i] = inf;    
  }
  stack<int> last;
  for(int i = 0; i < n; i++) {
    if(f[i] == 0) {
      last.push(i);
      low[i] = all_done;
    }
  }
  while(!last.empty()) {
    int now = last.top();
    last.pop();
    for(int i = 0; i < back[now].size(); i++) {
      int it = back[now][i];
      f[it]--;
      if(f[it] == 0) {
        last.push(it);
      }
      low[it] = min(low[it], low[now] - d[now]);
    }
  }
  /*
  for(int i = 0; i < n; i++) {
    printf("%d ", cost[i]);
  }
  printf("\n");
  for(int i = 0; i < n; i++) {
    printf("%d ", low[i]);
  }
  printf("\n");
  */
  
  bool ada = 0;
  for(int i = 0; i < n; i++) {
    assert(cost[i] + d[i] <= low[i]);
    if(cost[i] + d[i] < low[i]) {
      printf("%d %d\n", i, low[i] - cost[i] - d[i]);
      ada = 1;
    }
  }
  if(!ada) {
    puts("Tidak Ada Waktu");
  }
  return 0;
}

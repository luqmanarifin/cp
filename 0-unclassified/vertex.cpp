#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

int ch[N];
vector<int> edge[N];
int cnt, comp[N];
vector<int> comps[N];

void dfs(int now, int prev) {
  ch[now] = 1;
  for(auto it : edge[now]) {
    if(it == prev) continue;
    dfs(it, now);
    ch[now] += ch[it];
  }
}

void build(int now, int prev) {
  int mx = -1, p = -1;
  for(auto it : edge[now]) {
    if(it == prev) continue;
    if(ch[it] > mx) {
      mx = ch[it];
      p = it;
    }
  }
  comps[cnt].push_back(now);
  comp[now] = cnt;
  if(p == -1) return;
  build(p, now);
  for(auto it : edge[now]) {
    if(it != prev && it != p) {
      cnt++;
      build(it, now);
    }
  }
}

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n - 1; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    edge[a].push_back(b);
    edge[b].push_back(a);
  }
  dfs(1, -1);
  build(1, -1);
  int now = 0, feed;
  while(1) {
    int l = 0, r = (int) comps[now].size() - 1;
    while(l <= r) {
      int mid = (l + r) >> 1;
      printf("%d\n", comps[now][mid]);
      fflush(stdout);
      scanf("%d", &feed);
      if(feed == 0) return 0;
      if(comp[feed] != now) {
        now = comp[feed];
        break;
      }
      if(feed == comps[now][mid+1]) {
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
  }
  return 0;
}

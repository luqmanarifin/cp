#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N];
int dad[N];
vector<int> edge[N];

void dfs(int now, int prev) {
  for(auto it : edge[now]) {
    if(it == prev) {
      continue;
    }
    dfs(it, now);
    dad[it] = now;
  }
}

int main() {
  int n, q;
  scanf("%d %d", &n, &q);
  for(int i = 1; i <= n; i++) {
    scanf("%d", a + i);
  }
  int m = n - 1;
  while(m--) {
    int u, v;
    scanf("%d %d", &u, &v);
    edge[u].push_back(v);
    edge[v].push_back(u);
  }
  dfs(1, -1);
  while(q--) {
    int t, at, v;
    scanf("%d %d", &t, &at);
    if(t == 1) {
      bool ada = 0;
      int now = dad[at];
      while(now) {
        if(__gcd(a[now], a[at]) != 1) {
          ada = 1;
          printf("%d\n", now);
          break;
        }
        now = dad[now];
      }
      if(!ada) {
        puts("-1");
      }
    } else if(t == 2) {
      scanf("%d", &v);
      a[at] = v;
    }
  }
  return 0;
}

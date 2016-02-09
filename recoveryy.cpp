#include <bits/stdc++.h>

using namespace std;

const int N = 205;
const int inf = 1e9;

int cap[N][N], p[N], s, t, d[N];
int flow;

void augment(int now, int minflow) {
  if(s == now) {
    flow = minflow;
    return;
  }
  if(p[now] == -1) return;
  augment(p[now], min(minflow, cap[p[now]][now]));
  cap[p[now]][now] -= flow;
  cap[now][p[now]] += flow;
}

int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    memset(cap, 0, sizeof(cap));
    
    int n, m;
    scanf("%d %d", &n, &m);
    s = 2 * n;
    t = s + 1;
    for(int i = 0; i < n; i++) {
      cap[s][i] = 1;
      cap[i + n][t] = 1;
    }
    while(m--) {
      int u, v;
      scanf("%d %d", &u, &v);
      u--; v--;
      cap[u][v + n] = 1;
    }
    n = n * 2 + 2;
    int mf = 0;
    while(1) {
      flow = 0;
      for(int i = 0; i < n; i++) {
        p[i] = -1;
        d[i] = inf;
      }
      queue<int> q;
      q.push(s);
      d[s] = 0;
      while(!q.empty()) {
        int now = q.front();
        q.pop();
        if(now == t) {
          break;
        }
        for(int i = 0; i < n; i++) {
          if(cap[now][i] > 0 && d[i] > d[now] + 1) {
            p[i] = now;
            d[i] = d[now] + 1;
            q.push(i);
          }
        }
      }
      augment(t, inf);
      if(flow == 0) break;
      mf += flow;
    }
    n = (n - 2) / 2;
    printf("%d\n", n - mf);
  }
  return 0;
}

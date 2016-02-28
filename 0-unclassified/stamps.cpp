#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

vector<int> edge[N];
int a[N], h[N];
vector<pair<int, int>> p[N];
int done[N];

vector<int> S;

void dfs(int now) {
  if(done[now]) return;
  done[now] = 1;
  S.push_back(now);
  for(auto it : edge[now]) {
    dfs(it);
  }
}

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++) {
      scanf("%d", a + i);
    }
    for(int i = 0; i < N; i++) {
      p[i].clear();
    }
    for(int i = 0; i < N; i++) {
      h[i] = i;
    }
    
    while(m--) {
      int t, u, v;
      scanf("%d %d %d", &t, &u, &v);
      p[t].emplace_back(v, u);
    }
    for(int time = N - 1; time >= 0; time--) {
      vector<int> isi;
      for(auto it : p[time]) {
        edge[it.first].push_back(it.second);
        edge[it.second].push_back(it.first);
        isi.push_back(it.first);
        isi.push_back(it.second);
      }
      for(auto it : isi) {
        done[it] = 0;
      }
      for(auto it : isi) {
        if(!done[it]) {
          S.clear();
          dfs(it);
          int mk = -1;
          for(auto it : S) {
            mk = max(mk, h[it]);
          }
          for(auto it : S) {
            h[it] = mk;
          }
        }
      }
      for(auto it : isi) {
        edge[it].clear();
      }
    }

    long long ans = 0;
    for(int i = 0; i < n; i++) {
      ans += h[a[i]];
    }
    printf("%lld\n", ans);
  }
  return 0;
}

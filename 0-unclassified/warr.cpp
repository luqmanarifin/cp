#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 5;

int par[N];
int gol[N];
vector<int> p[N]; 

// return 0 if failed
// st = 1, if friend
int merge(int u, int v, int st) {
  if(par[u] == par[v]) {
    return (gol[u] == gol[v]) == st;
  }
  int flip = (gol[u] == gol[v]) != st;
  if(p[par[u]].size() < p[par[v]].size()) {
    for(auto it : p[par[u]]) {
      par[it] = par[v];
      if(flip) {
        gol[it] ^= 1;
      }
      p[par[v]].push_back(it);
    }
  } else {
    for(auto it : p[par[v]]) {
      par[it] = par[u];
      if(flip) {
        gol[it] ^= 1;
      }
      p[par[u]].push_back(it);
    }
  }
  return 1;
}

int main() {
  int n;
  while(~scanf("%d", &n)) {
    for(int i = 0; i < n; i++) {
      par[i] = i;
      gol[i] = 0;
      p[i].clear();
      p[i].push_back(i);
    }
    int t, u, v;
    scanf("%d %d %d", &t, &u, &v);
    while(t || u || v) {
      //printf("%d %d %d\n", t, u, v);
      if(t == 1) {
        if(!merge(u, v, 1)) {
          puts("-1");
        }
      } else if(t == 2) {
        if(!merge(u, v, 0)) {
          puts("-1");
        }
      } else if(t == 3) {
        if(par[u] == par[v] && gol[u] == gol[v]) {
          puts("1");
        } else {
          puts("0");
        }
      } else if(t == 4) {
        if(par[u] == par[v] && gol[u] != gol[v]) {
          puts("1");
        } else {
          puts("0");
        }
      } else {
        assert(false);
      }
      scanf("%d %d %d", &t, &u, &v);
    }
  }
  
  return 0;
}

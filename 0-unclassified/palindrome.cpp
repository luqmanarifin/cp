#include <bits/stdc++.h>

using namespace std;

const int N = 5e4 + 5;
const int lim = 1e6;
const int mod = 1e9 + 7;

int par[N], at[N];
vector<int> ins[N];
char s[N];
long long power[N];
bool done[N];

int find(int u) {
  if(par[u] != u) {
    par[u] = find(par[u]);
    at[par[u]] |= at[u];
  }
  return par[u];
}

// 1 if success, 0 if not
int merge(int u, int v) {
  int paru = find(u);
  int parv = find(v);
  if(paru == parv) {
    return 1;
  }
  if(at[paru] && at[parv] && at[paru] != at[parv]) {
    return 0;
  }
  par[paru] = parv;
  return 1;
}

int main() {
  power[0] = 1;
  for(int i = 1; i < N; i++) {
    power[i] = power[i - 1] * 26 % mod;
  }
  
  int t;
  scanf("%d", &t);
  while(t--) {
    memset(at, 0, sizeof(at));
    for(int i = 0; i < N; i++) {
      par[i] = i;
      ins[i].clear();
    }
    
    int n, m;
    scanf("%d %d", &n, &m);
    scanf("%s", s);
    for(int i = 0; i < n; i++) {
      if(s[i] == '?') {
        continue;
      }
      at[i] = s[i] - 'a' + 1;
    }
    vector<pair<int, int>> q;
    while(m--) {
      int a, b;
      scanf("%d %d", &a, &b);
      a--; b--;
      q.emplace_back(a, b);
    }
    sort(q.begin(), q.end());
    distance(q.begin(), unique(q.begin(), q.end()));
    for(auto it : q) {
      int a = it.first;
      int b = it.second;
      if((a + b) % 2 == 0) {
        ins[a].push_back(lim + (a + b) / 2);
      } else {
        ins[a].push_back((a + b) / 2 + 1);
      }      
    }
    
    ins[0].push_back(n % 2? lim + n / 2 : n / 2);
    set<int> now;
    int un = 0;
    for(int i = 0; i < n / 2; i++) {
      if(!merge(i, n - i - 1)) {
        puts("0");
        goto next;
      }
    }
    
    for(int i = 0; i < n; i++) {
      for(auto it : ins[i]) {
        now.insert(it);
      }
      now.erase(lim + i);
      now.erase(i);
      for(auto it : now) {
        if(it < lim) {
          if(!merge(i, 2 * it - i - 1)) {
            puts("0");
            goto next;
          }
        } else {
          if(!merge(i, 2 * (it - lim) - 1)) {
            puts("0");
            goto next;
          }
        }
      }
    }
    
    memset(done, 0, sizeof(done));
    for(int i = 0; i < n; i++) {
      int pak = find(i);
      if(done[pak]) {
        continue;
      }
      done[pak] = 1;
      un += (at[pak] == 0);
    }
    printf("%d\n", (int) power[un]);
    next:;
  }
  
  return 0;
}

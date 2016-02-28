#include <bits/stdc++.h>

using namespace std;

const int N = 5e4 + 5;
const int mod = 1e9 + 7;

int par[N];
int at[N];
char s[N];
long long power[N];
bool done[N];

int find(int u) {
  if(par[u] != u) {
    par[u] = find(par[u]);
  }
  return par[u];
}

// 1 if success, 0 if not
int merge(int u, int v) {
  int paru = find(u);
  int parv = find(v);
  if(at[paru] && at[parv] && at[paru] != at[parv]) {
    return 0;
  }
  par[paru] = parv;
  at[parv] |= at[paru];
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
    for(int i = 0; i < N; i++) {
      par[i] = i;
      at[i] = 0;
      done[i] = 0;
    }
  
    int n, m;
    scanf("%d %d %s", &n, &m, s);
    for(int i = 0; i < n; i++) {
      if(s[i] == '?') continue;
      at[i] = s[i] - 'a' + 1;
    }
    vector<pair<int, int>> q;
    while(m--) {
      int a, b;
      scanf("%d %d", &a, &b);
      a--; b--;
      q.emplace_back(a, b);
    }
    int ans = 0;
    for(int i = 0; i < n / 2; i++) {
      if(!merge(i, n - 1 - i)) {
        puts("0");
        goto next;
      }
    }
    for(auto it : q) {
      int a = it.first;
      int b = it.second;
      if(!merge(a, b)) {
        puts("0");
        goto next;
      }
    }
    for(int i = 0; i < n; i++) {
      int pak = find(i);
      if(done[pak]) continue;
      done[pak] = 1;
      if(at[pak] == 0) {
        ans++;
      }
    }
    printf("%d\n", (int) power[ans]);
    next:;
  }
  
  return 0;
}

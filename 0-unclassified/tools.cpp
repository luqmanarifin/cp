#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

// siapa dalem box (-1 kalo kosong)
int who[N];

// cuma berlaku buat parent untuk penunjuk box
int at[N];

int par[N];

int find(int u) {
  return par[u] == u? u : par[u] = find(par[u]);
}

void merge(int u, int v) {
  par[find(u)] = find(v);
}

int main() {
  for(int i = 0; i < N; i++) {
    par[i] = i;
    who[i] = i;
    at[i] = i;
  }
  
  int n, q;
  scanf("%d %d", &n, &q);
  while(q--) {
    int s, t;
    scanf("%d %d", &s, &t);
    assert(who[s] != -1);
    if(who[t] != -1) {
      merge(who[s], who[t]);
    }
    at[find(who[s])] = t;
    who[t] = find(who[s]);
    who[s] = -1;
  }
  for(int i = 1; i <= n; i++) {
    printf("%d ", at[find(i)]);
  }
  return 0;
}

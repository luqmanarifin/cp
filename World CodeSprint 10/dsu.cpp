#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

// dia di kelompok siapa
int par[N];

// siapa parent dari u
int find(int u) {
  if (par[u] == u) {
    return u;
  } else {
    return par[u] = find(par[u]);
  }
}

void merge(int u, int v) {
  par[find(u)] = find(v);
}

int main() {
  for (int i = 0; i < N; i++) par[i] = i;

  return 0;
}

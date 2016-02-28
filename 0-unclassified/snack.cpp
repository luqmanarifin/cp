#include <bits/stdc++.h>

using namespace std;

int par[1005];
int num[1005][1005];

int main() {
  int n;
  scanf("%d", &n);
  n *= 2;
  vector<tuple<int, int, int>> p;
  for(int i = 2; i <= n; i++) {
    for(int j = 1; j < i; j++) {
      scanf("%d", &num[i][j]);
      p.emplace_back(num[i][j], i, j);
    }
  }
  sort(p.begin(), p.end());
  reverse(p.begin(), p.end());
  for(auto it : p) {
    int c, a, b;
    tie(c, a, b) = it;
    if(par[a] || par[b]) {
      continue;
    }
    par[a] = b; par[b] = a;
  }
  for(int i = 1; i <= n; i++) {
    printf("%d ", par[i]);
  }
  return 0;
}

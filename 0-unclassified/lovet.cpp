// сука блять
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int mod = 1e9 + 7;

vector<pair<int, int>> edge[N];
int a[N];

bool dfs(int now, int c) {
  if(a[now] != -1) {
    return a[now] == c;
  }
  a[now] = c;
  for(auto it : edge[now]) {
    if(!dfs(it.first, c ^ it.second)) {
      return 0;
    }
  }
  return 1;
}

long long power(int a, int b) {
  if(b == 0) {
    return 1;
  }
  long long temp = power(a, b / 2);
  temp *= temp;
  temp %= mod;
  if(b & 1) {
    temp *= a;
    temp %= mod;
  }
  return temp;
}

int main() {
  memset(a, -1, sizeof(a));
  int n, m;
  scanf("%d %d", &n, &m);
  while(m--) {
    int u, v, c;
    scanf("%d %d %d", &u, &v, &c);
    edge[u].emplace_back(v, 1 - c);
    edge[v].emplace_back(u, 1 - c);
  }
  int comp = 0;
  for(int i = 1; i <= n; i++) {
    if(a[i] == -1) {
      comp++;
      if(!dfs(i, 0)) {
        puts("0");
        return 0;
      }
    }
  }
  cout << power(2, comp - 1) << endl;
  return 0;
}
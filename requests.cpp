#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;

vector<int> que[N], child[N];

int ans[N];
int h[N];
int f[N];
char s[N];

void dfs(int now, int d) {
  for(auto it : que[now]) {
    int to = h[it];
    ans[it] = f[to];
  }
  f[d] ^= (1 << (s[now] - 'a'));
  for(auto it : child[now]) {
    dfs(it, d + 1);
  }
  for(auto it : que[now]) {
    int to = h[it];
    ans[it] ^= f[to];
  }
}

int main() {
  int n, q;
  scanf("%d %d", &n, &q);
  for(int i = 1; i < n; i++) {
    int u;
    scanf("%d", &u);
    child[--u].push_back(i);
  }
  scanf("%s", s);
  for(int i = 0; i < q; i++) {
    int v;
    scanf("%d %d", &v, h + i);
    que[--v].push_back(i);
  }
  dfs(0, 1);
  for(int i = 0; i < q; i++) {
    puts((ans[i] & (ans[i] - 1)) == 0? "Yes" : "No");
  }
  return 0;
}

#include <bits/stdc++.h>

using namespace std;
const int N = 1e5, C = 100;
int A[N + 5];
int B[N + 5];
int num[N + 5];
int n, m;
vector<int> ve[N + 5];
bool visit[C + 5][N + 5];
int cycle[C + 5][N + 5];

inline void dfs(int c, int now){

  visit[c][now] = 1;
  num[now] = 1;
  for(int i = 0; i < (int) ve[now].size(); ++i){
    int u = ve[now][i];
    if(c < A[u] || c > B[u]) continue;
    if(!visit[c][u]){
      dfs(c, u);
    }
    if(cycle[c][u]) cycle[c][now] = true;
    else if(num[u] != -1) cycle[c][now] = true;
  }
  num[now] = -1;
}


int main() {
  scanf("%d%d", &n, &m);
  for(int i = 1;i <= n; ++i) scanf("%d", &A[i]);
  for(int i = 1;i <= n; ++i) scanf("%d", &B[i]);

  for(int i = 0;i < m; ++i){
    int x, y;
    scanf("%d%d", &x, &y);
    ve[x].push_back(y);
  }
  memset(num, -1, sizeof num);
  for(int c = 0; c <= C; ++c){
    for(int i = 1;i <= n; ++i){
      if(!visit[c][i] && c >= A[i] && c <= B[i]) dfs(c, i);
    }
  }
  int q;
  scanf("%d", &q);
  while(q--){
    int x, h;
    scanf("%d%d", &x, &h);
    puts(cycle[h][x] ? "Ya" : "Tidak");
  }
  return 0;
}
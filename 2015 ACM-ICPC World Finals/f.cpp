#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
#define fi first
#define se second
#define mp make_pair
#define pb push_back

const int M = 1e4 + 5;
const int N = 50;

int dist[M][N + 1][N + 1];
pii nex[N + 1][N + 1][4];
string s;
char ar[N + 5][N + 5];
int n, m;

pii arah[4] = {mp(0, -1), mp(-1, 0), mp(0, 1), mp(1, 0)};
bool valid(int x, int y){
  return x >= 0 && y >= 0 && x < n && y < m;
}

typedef tuple<int,int,int> iii;

queue<iii> q;

int main() {
  memset(nex, -1, sizeof nex);
  memset(dist, -1, sizeof dist);
  scanf("%d%d", &n, &m);
  for(int i = 0;i < n; ++i){
    scanf("%s", ar[i]);
  }
  for(int i = 0;i < n; ++i){
    for(int j = 0;j < m; ++j){
      for(int k = 0;k < 4; ++k){
        pii now = mp(i, j);
        while(valid(now.fi, now.se) && ar[now.fi][now.se] == ar[i][j]) {
          now.fi += arah[k].fi;
          now.se += arah[k].se;
        }
        if(valid(now.fi, now.se)) nex[i][j][k] = now;
      }
    }
  }

  string s;
  cin >> s;
  s += "*";
  int len = (int) s.length();
  q.push(make_tuple(0, 0, 0));
  dist[0][0][0] = 0;
  while(!q.empty()){
    int idx, x, y;
    tie(idx, x, y) = q.front(); q.pop();
    if(idx == (int)s.length()){
      printf("%d\n", dist[idx][x][y]);
      return 0;
    }
    if(ar[x][y] == s[idx]){
      if(dist[idx + 1][x][y] != -1) continue;
      dist[idx + 1][x][y] = dist[idx][x][y] + 1;
      q.push(make_tuple(idx + 1, x, y));
    }  
    else{
      for(int i = 0;i < 4; ++i){
        pii now = nex[x][y][i];
        if(!valid(now.fi, now.se)) continue;
        if(dist[idx][now.fi][now.se] == -1){
          dist[idx][now.fi][now.se] = dist[idx][x][y] + 1;
          q.push(make_tuple(idx, now.fi, now.se));
        }
      }
    }
  }

  return 0;
}

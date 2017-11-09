#include <bits/stdc++.h>

using namespace std;
const int N = 100;

vector<int> ve[N];
typedef pair<int,int> pii;
#define fi first
#define se second
#define mp make_pair

#define pb push_back
#define eb emplace_back
char ar[N * 10];
const int INF = 1e9;
int num[N + 5];

int main() {
  int n;
  while(scanf("%d", &n), n){
    gets(ar);
    for(int i = 1;i <= n; ++i){
      gets(ar);
      int len = strlen(ar);
      int now = 0;
      for(int j = 0;j < len; ++j){
        if(ar[j] == ' '){
          if(!now) continue;
          ve[i].eb(now);
          now = 0;
        }
        else{
          now *= 10;
          now += ar[j] - '0';
        }
      }
      if(now) ve[i].push_back(now);
    }
    int min_dist = INF;
    for(int i = 1;i <= n; ++i){
      fill(num, num + n + 1, -1);
      queue<pii> q;
      num[i] = 0;
      q.push({i, -1});
      while(!q.empty()){
        pii tmp = q.front(); q.pop();
        for(int j = 0;j < ve[tmp.fi].size(); ++j){
          int u = ve[tmp.fi][j];
          if(u != tmp.se){
            if(num[u] == -1){
              num[u] = num[tmp.fi] + 1;
              q.push({u, tmp.fi});
            }
            else{
              min_dist = min(min_dist, num[tmp.fi] + num[u] + 1);
              break;
            }
          }
        }
      }
    }
    if(min_dist == INF) puts("0");
    else printf("%d\n", min_dist);
    for(int i = 1;i <= n; ++i){
      ve[i].clear();
    }
  }

  return 0;
}

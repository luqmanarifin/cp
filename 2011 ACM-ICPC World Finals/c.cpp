#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
const int N = 200, M = 200;

char arr[N + 5][M + 5];
int ar[N + 5][M + 5];
bool visit[N + 5][M + 5];
int nilai[N + 5][M + 5];
int cnt[6];
char urut[] = {'W','A','K','J','S','D'};
int perm[] = {1, 5, 3, 2, 4, 0};
int n, m;

pii arah[4] = {mp(0,-1),mp(-1,0),mp(0,1),mp(1,0)};

bool valid(int X, int Y){
  return X >= 0 && Y >= 0 && X < n && Y < m;
}

void dfs(int x, int y, int idx){
  visit[x][y] = 1;
  nilai[x][y] = idx;
  for(int i = 0;i < 4; ++i){
    int xnow = x + arah[i].fi;
    int ynow = y + arah[i].se;
    if(valid(xnow, ynow) && !visit[xnow][ynow] && ar[xnow][ynow] == 1){
      dfs(xnow, ynow, idx);
    }
  }
}

int kena[N * M + 5];

int main() {
  for(int tc = 1; scanf("%d%d", &n, &m) == 2 && n && m; ++tc){
    for(int i = 0;i < n; ++i){
      scanf("%s", arr[i]);
      for(int j = 0; j < m; ++j){
        int bil;
        if(arr[i][j] >= '0' && arr[i][j] <= '9') bil = arr[i][j] - '0';
        else bil = arr[i][j] - 'a' + 10;
        for(int k = 0;k < 4; ++k){
          ar[i][j * 4 + k] = !!(bil & (1 << (3 - k)));
        }
      }
    }
    m <<= 2;
    /*
    for(int i = 0;i < n; ++i){
      for(int j = 0;j < m; ++j){
        fprintf(stderr, "%d", ar[i][j]);
      }
      fprintf(stderr, "\n");
    }*/
    for(int i = 0;i <= n; ++i) {
      fill(visit[i], visit[i] + m + 1, 0);
      fill(nilai[i], nilai[i] + m + 1, -1);
    }
    memset(cnt, 0, sizeof cnt);
    int idx = 0;
    for(int i = 0;i < n; ++i){
      for(int j = 0;j < m; ++j){
        if(!visit[i][j] && ar[i][j] == 1){
          idx++;
          dfs(i,j, idx);
        }
      }
    }
    //fprintf(stderr, "TOTAL CONNECTED COMPONENT: %d\n", idx);
    fill(kena, kena + idx + 1, 0);
    queue<pii> q;
    for(int i = 0;i < n; ++i){
      for(int j = 0;j < m; ++j){
        if(!visit[i][j] && ar[i][j] == 0){
          visit[i][j] = 1;
          q.push(mp(i, j));
          map<int,bool> MAP;
          while(!q.empty()){
            pii now = q.front(); q.pop();
            for(int k = 0;k < 4; ++k){
              int xnow = now.fi + arah[k].fi;
              int ynow = now.se + arah[k].se;
              if(!valid(xnow, ynow)){
                MAP[-1] = true;
              }
              else if(ar[xnow][ynow] == 1){
                MAP[nilai[xnow][ynow]] = true;
              }
              else if(!visit[xnow][ynow]){
                visit[xnow][ynow] = 1;
                q.push(mp(xnow, ynow));
              }
            }
          }
          if(MAP.size() == 1){
            int key = (MAP.begin())->first;
            kena[key]++;
          }
          MAP.clear();
        }
      }
    }
    
    for(int i = 1;i <= idx; ++i){
      cnt[kena[i]]++;
    }
    printf("Case %d: ", tc);
    for(int i = 0; i < 6; ++i){
      for(int j = 0;j < cnt[perm[i]]; ++j){
        printf("%c",urut[perm[i]]);
      }
    }
    printf("\n");
  }
  return 0;
}


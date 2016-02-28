#include <bits/stdc++.h>

using namespace std;

const int N = 105;

bool done[N][N], can[N][N];
int n;
vector<pair<int, int>> edge[N][N];

int db[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

bool valid(int i, int j) {
  return 1 <= i && i <= n && 1 <= j && j <= n;
}

int main() {
  freopen("lightson.in","r",stdin);
  freopen("lightson.out","w",stdout);
  
  int m;
  scanf("%d %d", &n, &m);
  while(m--) {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    edge[a][b].emplace_back(c, d);
  }
  can[1][1] = 1;
  done[1][1] = 1;
  queue<pair<int, int>> q;
  q.emplace(1, 1);
  while(!q.empty()) {
    int b, y;
    tie(b, y) = q.front();
    q.pop();
    for(auto it : edge[b][y]) {
      int r = it.first;
      int s = it.second;
      can[r][s] = 1;
      for(int i = 0; i < 4; i++) {
        int tb = r + db[i];
        int ty = s + dy[i];
        if(valid(tb, ty) && done[tb][ty] && !done[r][s]) {
          done[r][s] = 1;
          q.emplace(r, s);
        }
      }
    }
    for(int i = 0; i < 4; i++) {
      int tb = b + db[i];
      int ty = y + dy[i];
      if(valid(tb, ty) && can[tb][ty] && !done[tb][ty]) {
        done[tb][ty] = 1;
        q.emplace(tb, ty);
      }
    }
  }
  
  int ans = 0;
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      if(can[i][j]) {
        ans++;
      }
    }
  }
  cout << ans << endl;
  fclose(stdin);
  fclose(stdout);
  return 0;
}

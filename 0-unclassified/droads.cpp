#include <bits/stdc++.h>

using namespace std;

const int N = 3005;
const int inf = 1e9;

vector<int> edge[N];
int dist[N][N];

int main() {
  int n, m, id = 0;
  scanf("%d %d", &n, &m);
  for(int i = 0; i < m; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    edge[a].push_back(b);
    edge[b].push_back(a);
  }
  int s1, t1, l1, s2, t2, l2;
  scanf("%d %d %d", &s1, &t1, &l1);
  scanf("%d %d %d", &s2, &t2, &l2);
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      dist[i][j] = inf;
    }
    dist[i][i] = 0;
  }
  for(int i = 1; i <= n; i++) {
    queue<int> q;
    q.push(i);
    while(!q.empty()) {
      int now = q.front();
      q.pop();
      for(auto it : edge[now]) {
        if(dist[i][now] + 1 < dist[i][it]) {
          dist[i][it] = dist[i][now] + 1;
          q.push(it);
        }
      }
    }
  }
  if(dist[s1][t1] > l1 || dist[s2][t2] > l2) {
    puts("-1");
    return 0;
  }
  int ans = dist[s1][t1] + dist[s2][t2], cur;
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      bool ij1 = dist[s1][i] + dist[i][j] + dist[j][t1] <= l1;
      bool ji1 = dist[s1][j] + dist[j][i] + dist[i][t1] <= l1;
      bool ij2 = dist[s2][i] + dist[i][j] + dist[j][t2] <= l2;
      bool ji2 = dist[s2][j] + dist[j][i] + dist[i][t2] <= l2;
      if(ij1 && ij2) {
        ans = min(ans, dist[i][j] + dist[s1][i] + dist[j][t1] + dist[s2][i] + dist[j][t2]);
      }
      if(ji1 && ij2) {
        ans = min(ans, dist[i][j] + dist[s1][j] + dist[i][t1] + dist[s2][i] + dist[j][t2]);
      }
      if(ij1 && ji2) {
        ans = min(ans, dist[i][j] + dist[s1][i] + dist[j][t1] + dist[s2][j] + dist[i][t2]);
      }
      if(ji1 && ji2) {
        ans = min(ans, dist[i][j] + dist[s1][j] + dist[i][t1] + dist[s2][j] + dist[i][t2]);
      }
    }
  }
  cout << m - ans << endl;
  return 0;
}

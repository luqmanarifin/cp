#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9;
const int N = 505;

int source[N][N];
int dist[N][N];
int urut[N];
long long ans[N];

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      scanf("%d", &source[i][j]);
      dist[i][j] = inf;
    }
    dist[i][i] = 0;
  }
  for(int i = 0; i < n; i++) {
    scanf("%d", urut + i);
  }
  vector<int> ada;
  for(int u = n - 1; u >= 0; u--) {
    long long cur = 0;
    for(auto it : ada) {
      dist[urut[u]][it] = min(dist[urut[u]][it], source[urut[u]][it]);
      dist[it][urut[u]] = min(dist[it][urut[u]], source[it][urut[u]]);
    }
    for(int mid = 1; mid <= n; mid++) {
      for(int i = 1; i <= n; i++) {
        dist[i][urut[u]] = min(dist[i][urut[u]], dist[i][mid] + dist[mid][urut[u]]);
        dist[urut[u]][i] = min(dist[urut[u]][i], dist[urut[u]][mid] + dist[mid][i]);
      }
    }
    for(int i = 1; i <= n; i++) {
      for(int j = 1; j <= n; j++) {
        dist[i][j] = min(dist[i][j], dist[i][urut[u]] + dist[urut[u]][j]);
      }
    }
    ada.push_back(urut[u]);
    for(auto i : ada) {
      for(auto j : ada) {
        cur += dist[i][j];
      }
    }
    ans[u] = cur;
  }
  for(int i = 0; i < n; i++) {
    printf("%I64d ", ans[i]);
  }
  
  return 0;
}

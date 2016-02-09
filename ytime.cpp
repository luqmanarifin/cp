#include <bits/stdc++.h>

using namespace std;

const long long inf = 1e18;
const int N = 105;

long long dist[N];
int jar[N][N];
int x[N], y[N];
int a[N];

int main() {
  int n, d;
  scanf("%d %d", &n, &d);
  for(int i = 2; i < n; i++) {
    scanf("%d", a + i);
  }
  for(int i = 1; i <= n; i++) {
    scanf("%d %d", x + i, y + i);
  }
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      jar[i][j] = d * (abs(x[i] - x[j]) + abs(y[i] - y[j]));
    }
  }
  for(int i = 0; i < N; i++) {
    dist[i] = inf;
  }
  dist[1] = 0;
  for(int it = 0; it < n - 1; it++) {
    for(int i = 1; i <= n; i++) {
      for(int j = 1; j <= n; j++) {
        if(i != j) {
          if(dist[i] + jar[i][j] - a[j] < dist[j]) {
            dist[j] = dist[i] + jar[i][j] - a[j];
          }
        }
      }
    }
  }
  cout << dist[n] << endl;
  return 0;
}

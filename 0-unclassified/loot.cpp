#include <bits/stdc++.h>

using namespace std;

const int offset = 200;
const int N = 905;
const int inf = 2e9;

int f[N][3];
int tmp[N][3];

int main() {
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < 3; j++) {
      f[i][j] = -inf;
    }
  }
  f[offset][0] = 0;
  
  int n, m;
  scanf("%d %d", &n, &m);
  for(int it = 0; it < n; it++) {
    int p, w, d;
    scanf("%d %d %d", &p, &w, &d);
    for(int i = 0; i < N; i++) {
      for(int j = 0; j < 3; j++) {
        tmp[i][j] = f[i][j];
      }
    }
    
    for(int i = 0; i < N; i++) {
      for(int j = 0; j < 3; j++) {
        int to = i + w;
        if(0 <= to && to < N) {
          tmp[to][j] = max(tmp[to][j], f[i][j] + p);
        }
        to = i + w - d;
        if(0 <= to && to < N && j < 2) {
          tmp[to][j + 1] = max(tmp[to][j + 1], f[i][j] + p);
        }
      }
    }
    
    for(int i = 0; i < N; i++) {
      for(int j = 0; j < 3; j++) {
        f[i][j] = tmp[i][j];
      }
    }
  }
  int ans = 0;
  for(int i = 0; i <= m + offset; i++) {
    for(int j = 0; j < 3; j++) {
      ans = max(ans, f[i][j]);
    }
  }
  cout << ans << endl;
  return 0;
}

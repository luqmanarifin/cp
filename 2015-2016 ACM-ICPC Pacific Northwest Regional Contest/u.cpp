#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int da[] = {1, 1, 1, 0, 0, 0, -1, -1, -1};
int db[] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};

int a[N][N], b[N][N];

int main() {
  int n, m, t;
  scanf("%d %d %d", &m, &n, &t);
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      scanf("%d", &a[i][j]);
    }
  }
  while(t--) {
    memset(b, 0, sizeof(b));
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        for(int t = 0; t < 9; t++) {
          int ti = (i + da[t] + n) % n;
          int tj = (j + db[t] + m) % m;
          b[i][j] += a[ti][tj];
        }
      }
    }
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        a[i][j] = b[i][j];
      }
    }
  }
  set<int> s;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      s.insert(a[i][j]);
    }
  }
  cout << s.size() << endl;
  return 0;
}
#include <bits/stdc++.h>

using namespace std;

const int N = 105;

char s[N][N];

int da[] = {0, 0, 1, -1};
int db[] = {1, -1, 0, 0};

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; i++) scanf("%s", s[i]);
  int ans = 0;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(s[i][j] == 'W') {
        for(int k = 0; k < 4; k++) {
          int pi = i + da[k];
          int pj = j + db[k];
          if(0 <= pi & pi < n && 0 <= pj && pj < m) {
            if(s[pi][pj] == 'P') {
              ans++;
              break;
            }
          }
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}

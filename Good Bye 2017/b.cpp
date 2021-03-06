#include <bits/stdc++.h>

using namespace std;

const int N = 55;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int n, m, d[5];
char s[N][N], ins[105];

bool valid(int i, int j) {
  return 0 <= i && i < n && 0 <= j && j < m;
}

int main() {
  scanf("%d %d", &n, &m);
  int si, sj, ei, ej;
  for (int i = 0; i < n; i++) {
    scanf("%s", s[i]);
    for (int j = 0; j < m; j++) {
      if (s[i][j] == 'S') {
        si = i;
        sj = j;
      }
      if (s[i][j] == 'E') {
        ei = i;
        ej = j;
      }
    }
  }
  scanf("%s", ins);
  int len = strlen(ins);
  
  for (int i = 0; i < 4; i++) d[i] = i;
  int ans = 0;
  do {
    int pi = si, pj = sj;
    bool ok = 0;
    for (int i = 0; i < len; i++) {
      pi += dx[d[ins[i] - '0']];
      pj += dy[d[ins[i] - '0']];
      if (!valid(pi, pj)) break;
      if (s[pi][pj] == '#') break;
      if (pi == ei && pj == ej) {
        ok = 1;
        break;
      }
    }
    if (ok) ans++;
  } while (next_permutation(d, d + 4));
  cout << ans << endl;
  return 0;
}

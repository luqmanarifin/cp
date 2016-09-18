#include <bits/stdc++.h>

using namespace std;

const int N = 205;

int di[256], dj[256];
char rev[256];
char junk[N];

bool done[N][N];
char s[N][N][10];
int d[N][N];

void dfs(int ni, int nj) {
  done[ni][nj] = 1;
  scanf("%s", s[ni][nj]);
  int len = strlen(s[ni][nj]);
  for (int i = 0; i < len; i++) {
    if (s[ni][nj][i] == '*') continue;
    int ti = ni + di[s[ni][nj][i]];
    int tj = nj + dj[s[ni][nj][i]];
    if (done[ti][tj]) continue;
    printf("%c\n", s[ni][nj][i]);
    fflush(0);
    dfs(ti, tj);
    printf("%c\n", rev[s[ni][nj][i]]);
    fflush(0);
    scanf("%s", junk);
  }
}

int main() {
  di['N'] = -1; dj['N'] = 0; rev['N'] = 'S';
  di['S'] = 1; dj['S'] = 0; rev['S'] = 'N';
  di['W'] = 0; dj['W'] = -1; rev['W'] = 'E';
  di['E'] = 0; dj['E'] = 1; rev['E'] = 'W';
  
  int t;
  scanf("%d", &t);
  while (t--) {
    memset(done, 0, sizeof(done));
    dfs(100, 100);
    
    
    memset(d, -1, sizeof(d));
    d[100][100] = 0;
    queue<pair<int, int>> q;
    q.emplace(100, 100);
    bool ans = 0;
    while (!q.empty()) {
      int ni, nj;
      tie(ni, nj) = q.front();
      q.pop();
      int len = strlen(s[ni][nj]);
      if (s[ni][nj][len - 1] == '*') {
        printf("%d\n", d[ni][nj]);
        fflush(0);
        ans = 1;
        break;
      }
      for (int i = 0; i < len; i++) {
        int ti = ni + di[s[ni][nj][i]];
        int tj = nj + dj[s[ni][nj][i]];
        if (d[ti][tj] == -1) {
          d[ti][tj] = d[ni][nj] + 1;
          q.emplace(ti, tj);
        }
      }
    }
    if (ans == 0) {
      printf("-1\n");
      fflush(0);
      continue;
    }
  }
  return 0;
}

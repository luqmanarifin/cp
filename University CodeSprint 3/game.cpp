#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

char s[N][N];
int nim[N][N];
int n;

int dx[] = {0, -1, -1};
int dy[] = {-1, -1, 0};

bool valid(int i, int j) {
  return 0 <= i && i < n && 0 <= j && j < n;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%s", s[i]);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        set<int> ada;
        for (int k = 0; k < 3; k++) {
          int ti = i + dx[k];
          int tj = j + dy[k];
          if (valid(ti, tj) && s[ti][tj] != 'X') {
            ada.insert(nim[ti][tj]);
          }
        }
        for (int k = 0; ; k++) {
          if (!ada.count(k)) {
            nim[i][j] = k;
            break;
          }
        }
      }
    }
    int tot = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (s[i][j] == 'K') {
          tot ^= nim[i][j];
        }
      }
    }
    if (tot == 0) {
      puts("LOSE");
      continue;
    }
    int ways = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (s[i][j] == 'K') {
          int cur = tot ^ nim[i][j];
          for (int k = 0; k < 3; k++) {
            int ti = i + dx[k];
            int tj = j + dy[k];
            if (valid(ti, tj) && s[ti][tj] != 'X' && nim[ti][tj] == cur) {
              ways++;
            }
          }
        }
      }
    }
    printf("WIN %d\n", ways);
  }

  return 0;
}

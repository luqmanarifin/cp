#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

string dir = "LRDU";
int pos[256];

int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};

char s[N];

int main() {
  for (int i = 0; i < 4; i++) {
    pos[dir[i]] = i;
  }
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m;
    scanf("%d %d %s", &n, &m, s);
    int len = strlen(s);
    int min_i = 0, max_i = 0, min_j = 0, max_j = 0;
    int now_i = 0, now_j = 0;
    for (int i = 0; i < len; i++) {
      int nex_min_i = min_i, nex_max_i = max_i, nex_min_j = min_j, nex_max_j = max_j;
      int c = pos[s[i]];
      now_i += dx[c];
      now_j += dy[c];
      nex_min_i = min(nex_min_i, now_i);
      nex_max_i = max(nex_max_i, now_i);
      nex_min_j = min(nex_min_j, now_j);
      nex_max_j = max(nex_max_j, now_j);
      // printf("%d %d - %d %d\n", nex_min_i, nex_max_i, nex_min_j, nex_max_j);
      if (nex_max_i - nex_min_i >= n || nex_max_j - nex_min_j >= m) {
        now_i -= dx[c];
        now_j -= dy[c];
        // printf("break when processing %d\n", i);
        break;
      } else {
        min_i = nex_min_i;
        max_i = nex_max_i;
        min_j = nex_min_j;
        max_j = nex_max_j;
      }
    }
    printf("%d %d\n", 1 - min_i, 1 - min_j);
  }

  return 0;
}

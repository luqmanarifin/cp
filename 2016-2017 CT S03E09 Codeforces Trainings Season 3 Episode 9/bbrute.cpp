#include <bits/stdc++.h>

using namespace std;

const int N = 25;

int a[N][N], n;
int b[N][N];
bool bisa[1 << 21];

int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};

bool valid(int i, int j) {
  return 0 <= i && i < n && 0 <= j && j < n && i + j < n;
}

int main() {
  for (n = 2; n <= 4; n++) {
    memset(bisa, 0, sizeof(bisa));
    queue<int> q;
    q.push(0);
    bisa[0] = 1;
    int all = 0;
    while (!q.empty()) {
      int now = q.front();
      int crot = now;
      q.pop();
      //printf("%d\n", now);
      int p = 0;
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
          a[i][j] = now % 2;
          b[i][j] = p++;
          now /= 2;
        }
      }
      all = p;
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
          for (int k = 0; k < 4; k += 2) {
            int pa = i + dx[k];
            int pb = j + dy[k];
            int qa = i + dx[(k + 1) % 4];
            int qb = j + dy[(k + 1) % 4];
            if (!valid(pa, pb) || !valid(qa, qb)) continue;
            int mask = crot;
            mask ^= (1 << b[i][j]);
            mask ^= (1 << b[pa][pb]);
            mask ^= (1 << b[qa][qb]);
            if (!bisa[mask]) {
              bisa[mask] = 1;
              q.push(mask);
            }
          }
        }
      }
    }
    
    for (int t = 0; t < (1<<all); t++) {
      int now = t;
      printf("%d\n", bisa[t]);
      //if (bisa[t])
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
          a[i][j] = now % 2;
          printf("%d", a[i][j]);
          now /= 2;
        }
        printf("\n");
      }
      printf("\n");
    }
    
  }

  return 0;
}

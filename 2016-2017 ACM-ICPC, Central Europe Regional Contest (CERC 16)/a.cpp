#include <bits/stdc++.h>

using namespace std;

const int N = 200;
const long long PRIME = 1e9 + 7;
const long long MOD = 2e9 + 89;

char s[N][N], tmp[N][N];
long long power[N * N];
bool okx[N], oky[N];

void rotate(int a, int b, int sz_n, int sz_m) {
  for (int i = 0; i < sz_n; i++) {
    for (int j = 0; j < sz_m; j++) {
      tmp[i][j] = s[a + i][b + j];
    }
  }
  for (int i = 0; i < sz_n; i++) {
    for (int j = 0; j < sz_m; j++) {
      s[a + i][b + j] = tmp[sz_m - j - 1][i];
    }
  }
}

void rotate_2(int a, int b, int n, int m) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      tmp[i][j] = s[a + i][b + j];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      s[a + i][b + j] = tmp[n - i - 1][m - j - 1];
    }
  }
}

int main() {
  power[0] = 1;
  for (int i = 1; i < N * N; i++) power[i] = power[i - 1] * PRIME % MOD;
  
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%s", s[i]);
  }
  int sz_n, sz_m, ada_n, ada_m;
  int x = 0, y = 0;
  for (int i = 0; i < n; i++) if (s[i][1] == '#') x++;
  for (int j = 0; j < m; j++) if (s[1][j] == '#') y++;
  ada_n = x - 1;
  ada_m = y - 1;
  sz_n = (n - x) / ada_n;
  sz_m = (m - y) / ada_m;
  
  //~ printf("size %d %d\n", sz_n, sz_m);
  
  set<long long> all;
  for (int p = 0; p < ada_n; p++) {
    for (int q = 0; q < ada_m; q++) {
      int a = p * sz_n + p + 1;
      int b = q * sz_m + q + 1;
      long long h = MOD;
      
      if (sz_n == sz_m) {
        for (int k = 0; k < 4; k++) {
          long long now = 0; 
          for (int i = 0; i < sz_n; i++) {
            for (int j = 0; j < sz_m; j++) {
              int id = i * sz_m + j;
              if (s[a + i][b + j] == '+') {
                now += power[id];
                now %= MOD;
              }
            }
          }
          h = min(h, now);
          rotate(a, b, sz_n, sz_m);
        }
      } else {
        for (int k = 0; k < 2; k++) {
          long long now = 0; 
          for (int i = 0; i < sz_n; i++) {
            for (int j = 0; j < sz_m; j++) {
              int id = i * sz_m + j;
              if (s[a + i][b + j] == '+') {
                now += power[id];
                now %= MOD;
              }
            }
          }
          h = min(h, now);
          rotate_2(a, b, sz_n, sz_m);
        }
      }
      all.insert(h);
    }
  }
  cout << all.size() << endl;
  return 0;
}

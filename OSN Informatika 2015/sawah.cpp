#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

int da[] = {0, 1, 0, -1};
int db[] = {1, 0, -1, 0};

int t[][4] = {
  {0, 1, 2, 3},
  {0, 1, 3, 0},
  {0, 1, 2, 0},
  {1, 2, 3, 0},
  {0, 2, 3, 0},
  {0, 3, 0, 0},
  {1, 2, 0, 0}
};
int sz[] = {4, 3, 3, 3, 3, 2, 2};

int dp[N][N][10];
int num[N][N], n, m;
char junk[N];

int find(int a, int b, int c, int d, int s) {
  if(a > c || b > d) return 0;
  return dp[c][d][s] - dp[c][b - 1][s] - dp[a - 1][d][s] + dp[a - 1][b - 1][s];
}  

bool valid(int i, int j) {
  return 1 <= i && i <= n && 1 <= j && j <= m;
}

int main() {
  int k, q;
  scanf("%s %d %d %d", junk, &n, &m, &q);
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
      scanf("%d", &num[i][j]);
    }
  }
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
      for(int k = 0; k < 7; k++) {
        for(int d = 0; d < sz[k]; d++) {
          int ta = i + da[t[k][d]];
          int tb = j + db[t[k][d]];
          if(!valid(ta, tb)) goto TO;
          if(num[i][j] < num[ta][tb]) goto TO;
        }
        dp[i][j][k]++;
        TO:;
      }
    }
  }
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
      for(int k = 0; k < 7; k++) {
        dp[i][j][k] += dp[i][j - 1][k] + dp[i - 1][j][k] - dp[i - 1][j - 1][k];
      }
    }
  }
  while(q--) {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int ka = b - a + 1;
    int kb = d - c + 1;
    if(ka == 1 && kb == 1) {
      puts("Kiri Atas");
      continue;
    }
    if(find(a + 1, b + 1, c - 1, d - 1, 0) && ka >= 3 && kb >= 3) {
      puts("Tidak Mungkin");
      continue;
    }
    if(find(a + 1, b, c - 1, b, 1) && ka >= 3) {
      puts("Tidak Mungkin");
      continue;
    }
    if(find(a, b + 1, a, d - 1, 2) && kb >= 3) {
      puts("Tidak Mungkin");
      continue;
    }
    if(find(a + 1, d, c - 1, d, 3) && ka >= 3) {
      puts("Tidak Mungkin");
      continue;
    }
    if(find(c, b + 1, c, d - 1, 4) && kb >= 3) {
      puts("Tidak Mungkin");
      continue;
    }
    if(find(c, b, c, b, 5) && ka >= 2) {
      puts("Tidak Mungkin");
      continue;
    }
    if(find(a, d, a, d, 6) && kb >= 2) {
      puts("Tidak Mungkin");
      continue;
    }
    bool kiri = 1, kanan = 1;
    if(a + 1 <= c) {
      if(num[a][b] < num[a + 1][b]) {
        kiri = 0;
      }
      if(num[c][d] < num[c - 1][d]) {
        kanan = 0;
      }
    }
    if(b + 1 <= d) {
      if(num[a][b] < num[a][b + 1]) {
        kiri = 0;
      }
      if(num[c][d] < num[c][d - 1]) {
        kanan = 0;
      }
    }
    if(kiri && !kanan) {
      puts("Kiri Atas");
    } else if(kanan && !kiri) {
      puts("Kanan Bawah");
    } else {
      puts("Tidak Mungkin");
    }
  }
  return 0;
}
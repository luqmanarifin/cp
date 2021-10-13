#include <bits/stdc++.h>

using namespace std;

const int N = 45;
const int offset = 40;
const int MAX_OFFSET = 81;

struct state {
  int a, d, e, f;
  char prev;
}; 

// pos - R - B - (R - B) - %A - %B
bool dp[N][MAX_OFFSET][40][40];
state x[N][MAX_OFFSET][40][40];

void update(int a, int d, int e, int f, state st) {
  // int val = ((a * MAX_OFFSET + d) * 40 + e) * 40 + f;
  x[a][d][e][f] = st;
}

state fetch(int a, int d, int e, int f) {
  return x[a][d][e][f];
}

char s[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    memset(dp, 0, sizeof(dp));

    int n, A, B;
    scanf("%d %d %d %s", &n, &A, &B, s + 1);
    dp[0][offset][0][0] = 1;
    for (int i = 1; i <= n; i++) {
      int add = (s[i] - '0');
      for (int pos = 0; pos < MAX_OFFSET; pos++) {
        for (int a = 0; a < A; a++) {
          for (int b = 0; b < B; b++) {
            if (!dp[i-1][pos][a][b]) continue;
            // printf("%d %d %d %d %d %d\n", i-1, dr, db, pos, a, b);
            state use_r = {i - 1, pos, a, b, 'R'};
            state use_b = {i - 1, pos, a, b, 'B'};

            // use R
            if (pos + 1 < MAX_OFFSET) {
              // printf("use r\n");
              dp[i][pos+1][(a * 10 + add) % A][b] = 1;
              update(i, pos+1, (a * 10 + add) % A, b, use_r);
            }

            // use B
            if (pos >= 1) {
              // printf("use b\n");
              dp[i][pos-1][a][(b * 10 + add) % B] = 1;
              update(i, pos-1, a, (b * 10 + add) % B, use_b);
            }
          }
        }
      }
    }
    vector<int> best(1, offset);
    for (int i = 1; i <= n - 1; i++) {
      best.push_back(offset + i);
      best.push_back(offset - i);
    }
    bool found = 0;
    for (auto it : best) {
      if (dp[n][it][0][0]) {
        string ans = "";
        found = 1;
        int a = n, d = it, e = 0, f = 0;
        while (a > 0) {
          state bac = fetch(a, d, e, f);
          ans += bac.prev;
          a = bac.a;
          d = bac.d;
          e = bac.e;
          f = bac.f;
        }
        reverse(ans.begin(), ans.end());
        printf("%s\n", ans.c_str());
        break;
      }
    }
    if (!found) {
      printf("-1\n");
    }
  }

  return 0;
}

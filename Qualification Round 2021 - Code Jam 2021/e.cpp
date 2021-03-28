#include <bits/stdc++.h>

using namespace std;

const int N = 105;
const int M = 10005;

int n, m, score[N], diff[M];
long long disc[N];
char s[N][M];

int main() {
  n = 100; m = 10000;

  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    memset(score, 0, sizeof(score));
    memset(diff, 0, sizeof(diff));
    memset(disc, 0, sizeof(disc));

    int v;
    scanf("%d", &v);
    for (int i = 0; i < n; i++) {
      scanf("%s", s[i]);
      for (int j = 0; j < m; j++) {
        if (s[i][j] == '1') {
          score[i]++;
          diff[j]++;
        }
      }
    }
    // puts("anjing");
    for (int j = 0; j < m; j++) {
      diff[j] *= 100;
    }
    int max_score = -1, px = -1;
    for (int i = 0; i < n; i++) {
      // printf("%d %d\n", i + 1, score[i]);
      if (score[i] > max_score) {
        max_score = score[i];
        px = i;
      }
    }
    // printf("max score %d: %d\n", px + 1, max_score);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (score[i] > diff[j]) {

          if (s[i][j] == '1') {
            disc[i] += score[i] - diff[j];
          }

        } else if (score[i] < diff[j]) {

          if (s[i][j] == '0') {
            disc[i] += diff[j] - score[i];
          }

        }
      }
    }
    long long mx = -1; int p = -1;
    for (int i = 0; i < n; i++) {
      if (score[i] <= 5000) continue;
      if (disc[i] > mx) {
        mx = disc[i];
        p = i;
      }
    }
    printf("Case #%d: %d\n", tt, px + 1);
  }

  return 0;
}

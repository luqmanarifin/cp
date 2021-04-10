#include <bits/stdc++.h>

using namespace std;

long long gcd(long long a, long long b) { return a ? gcd(b % a, a) : b; }

char s[5][125];
int score[5];

char ans[125];

int main() {
  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    memset(ans, 0, sizeof(ans));

    int n, q;
    scanf("%d %d", &n, &q);
    for (int i = 0; i < n; i++) {
      scanf("%s %d", s[i], score + i);
    }

    int sum = 0;
    for (int j = 0; j < q; j++) {
      int best_f = 0, best_t = 0;
      for (int i = 0; i < n; i++) {
        int cur_f = 0, cur_t = 0;
        if (s[i][j] == 'T') {
          cur_t = score[i];
          cur_f = q - score[i];
        } else {
          cur_f = score[i];
          cur_t = q - score[i];
        }
        best_f = max(best_f, cur_f);
        best_t = max(best_t, cur_t);
      }
      if (best_f > best_t) {
        ans[j] = 'F';
        sum += best_f;
      } else {
        ans[j] = 'T';
        sum += best_t;
      }
    }
    int fpb = gcd(sum, q);
    printf("Case #%d: %s %d/%d\n", tt, ans, sum / fpb, q / fpb);
  }

  return 0;
}

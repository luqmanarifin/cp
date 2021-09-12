#include <bits/stdc++.h>

using namespace std;

const int N = 8e5 + 5;
const long long mod = 1e9 + 7;

char s[N];

void add(long long& at, long long val) {
  at += val;
  at %= mod;
}

int main() {
  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    int n;
    scanf("%d %s", &n, s + 1);

    int last_o = 0, last_x = 0;
    long long sum = 0, ans = 0;
    char now = 'F';
    for (int i = 1; i <= n; i++) {
      if (s[i] == 'O') {
        if (now == 'X') { 
          add(sum, last_x);
        }
        now = s[i];
        last_o = i;
      } else if (s[i] == 'X') {
        if (now == 'O') {
          add(sum, last_o);
        }
        now = s[i];
        last_x = i;
      }
      add(ans, sum);
    }
    printf("Case #%d: %lld\n", tt, ans);
  }

  return 0;
}


#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

long long x[N];
int d[N];
char c[N];
int s[N][3], f[N][3];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%lld %c", x + i, c + i);
  for (int i = 1; i <= n; i++) {
    if (c[i] == 'R') d[i] = 0;
    else if (c[i] == 'B') d[i] = 1;
    else d[i] = 2;
    
    s[i][d[i]]++;
    for (int j = 0; j < 3; j++) s[i][j] += s[i-1][j];
  }
  for (int i = n; i >= 1; i--) {
    f[i][d[i]]++;
    for (int j = 0; j < 3; j++) f[i][j] += f[i+1][j];
  }
  long long ans = 0;
  for (int i = 2; i <= n; i++) {
    long long dist = x[i] - x[i-1];
    if (d[i] + d[i-1] == 1) {
      int kali = 0;
      kali += !!f[i][d[i-1]];
      kali += !!s[i-1][d[i]];
      ans += kali * dist;
    } else if (d[i] + d[i-1] == 4) {
      ans += dist;
    } else {
      int kali = 1;
      if (d[i-1] <= 1) {
        if (s[i-1][d[i-1]^1] && f[i][d[i-1]^1]) {
          //printf("lef %d %d\n", s[i-1][d[i-1]], f[i][d[i-1]]);
          kali = 2;
        }
      }
      if (d[i] <= 1) {
        if (s[i-1][d[i]^1] && f[i][d[i]^1]) {
          //printf("rig %d %d\n", s[i-1][d[i]], f[i][d[i]]);
          kali = 2;
        }
      }
      ans += dist * kali;
    }
    //cout << ans << endl;
  }
  cout << ans << endl;
  return 0;
}

#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

char s[2][N];
int done[2][N], bad[2][N];

int main() {
  int t;
  scanf("%d", &t);
  for(int tt = 1; tt <= t; tt++) {
    for(int i = 0; i < N; i++) {
      bad[0][i] = bad[1][i] = 1;
      done[0][i] = done[1][i] = 0;
    }
    
    int n;
    scanf("%d %s %s", &n, s[0], s[1]);
    for(int j = 0; j < 2; j++) {
      for(int i = 0; i < n; i++) {
        if(s[j][i] == 'X') {
          bad[j][i] = 0;
        } else {
          if(i + 1 < n && s[j][i + 1] == '.') {
            bad[j][i] = 0;
          }
          if(i && s[j][i - 1] == '.') {
            bad[j][i] = 0;
          }
        }
      }
    }
    int ans = 0;
    for(int j = 0; j < 2; j++) {
      for(int i = 0; i < n; i++) {
        if(s[j][i] == '.' && !bad[j][i]) {
          ans++;
          bool ok = 1;
          for(; i < n && s[j][i] == '.'; i++) {
            if(ok && bad[j ^ 1][i]) {
              done[j ^ 1][i] = 1;
              ok = 0;
            }
          }
        }
      }
    }
    for(int i = 0; i < n; i++) {
      ans += (bad[0][i] && !done[0][i]) || (bad[1][i] && !done[1][i]);
    }
    printf("Case #%d: %d\n", tt, ans);
    cerr << tt << " udah!" << endl;
  }
  return 0;
}

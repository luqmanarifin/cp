#include <bits/stdc++.h>

using namespace std;

const int N = 105;

char s[N][N][5];
int a[N][N];
bool sip[N][N];
int t[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%s", s[i][j]);
      if (strlen(s[i][j]) == 3) {
        sip[i][j] = 1;
      } else {
        a[i][j] = atoi(s[i][j]);
      }
    }
  }
  int q;
  scanf("%d", &q);
  for (int i = 0; i < q; i++) {
    scanf("%d", t + i);
    t[i]--;
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    bool nol = 0;
    int now = 0;
    for (int j = 0; j < q; j++) {
      if (sip[i][t[j]] == 0 && a[i][t[j]] == 0) {
        nol = 1;
      }
      if (sip[i][t[j]] == 1) {
        now--;
      }
      if (sip[i][t[j]] == 0 && a[i][t[j]] == 2) {
        now++;
      }
    }
    ans += (nol == 0 && now >= 1);
  }
  cout << ans << endl;
  return 0;
}

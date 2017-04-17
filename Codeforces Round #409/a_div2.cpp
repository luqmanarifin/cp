#include <bits/stdc++.h>

using namespace std;

const int N = 105;

char s[N];

int solve() {
  int n = strlen(s);
  int ans = 0;
  for (int i = 0; i + 1 < n; i++) {
    if (s[i] == 'V' && s[i+1] == 'K') {
      ans++;
    }
  }
  return ans;
}

int main() {
  scanf("%s", s);
  int n = strlen(s);
  int ans = solve();
  for (int i = 0; i < n; i++) {
    if (s[i] == 'V') s[i] = 'K';
    else s[i] = 'V';
    ans = max(ans, solve());
    if (s[i] == 'V') s[i] = 'K';
    else s[i] = 'V';
  }
  cout << ans << endl;
  return 0;
}
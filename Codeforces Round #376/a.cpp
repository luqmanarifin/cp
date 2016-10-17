#include <bits/stdc++.h>

using namespace std;

char s[105];

int main() {
  scanf("%s", s);
  int n = strlen(s);
  int ans = 0, now = 0;
  for (int i = 0; i < n; i++) {
    int diff = abs(now - (s[i] - 'a'));
    ans += min(diff, 26 - diff);
    now = s[i] - 'a';
  }
  cout << ans << endl;
  return 0;
}

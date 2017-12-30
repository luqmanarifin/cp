#include <bits/stdc++.h>

using namespace std;

const int N = 105;

char s[N];

int main() {
  scanf("%s", s);
  int n = strlen(s);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if ('0' <= s[i] && s[i] <= '9') {
      ans += (s[i] - '0') % 2;
    }
    if (s[i] == 'a' || s[i] == 'i' || s[i] == 'u' || s[i] == 'e' || s[i] == 'o') {
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}

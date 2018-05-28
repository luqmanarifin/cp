#include <bits/stdc++.h>

using namespace std;

const int N = 55;

char s[N];

int main() {
  scanf("%s", s);
  int n = strlen(s);
  int ans = 0;
  for (int len = 2; len <= n; len++) {
    for (int st = 0; st + len <= n; st++) {
      bool palin = 1;
      for (int i = 0; i < len; i++) {
        if (s[st + i] != s[st + len - 1 - i]) {
          palin = 0;
        }
      }
      if (!palin) {
        ans = max(ans, len);
      }
    }
  }
  cout << ans << endl;
  return 0;
}

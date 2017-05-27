#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

char s[N];

int main() {
  scanf("%s", s);
  int n = strlen(s), ans = 0;
  bool ok = 0;
  for (int i = n - 1; i >= 0; i--) {
    if (!ok) {
      if (s[i] == '1') {
        ans++;
        ok = 1;
      }
    } else {
      ans += (s[i] != s[i+1]);
    }
  }
  cout << ans << endl;
  return 0;
}


#include <bits/stdc++.h>

using namespace std;

const int N = 105;

char s[N];

int main() {
  int n;
  scanf("%d %s", &n, s);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    ans++;
    if (i + 1 < n && s[i] != s[i + 1]) {
      i++;
    }
  }
  cout << ans << endl;
  return 0;
}

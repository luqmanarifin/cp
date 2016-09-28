#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

char s[N];

int main() {
  scanf("%s", s);
  int n = strlen(s);
  int ans = 1;
  for (int i = 0; i < n; i++) {
    if ('A' <= s[i] && s[i] <= 'Z') {
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}

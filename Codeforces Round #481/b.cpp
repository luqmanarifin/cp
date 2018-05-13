#include <bits/stdc++.h>

using namespace std;

string s;
int n;

int main() {
  cin >> n >> s;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] != 'x') continue;
    int j = i;
    while (j + 1 < n && s[j + 1] == s[j]) j++;
    int len = j - i + 1;
    if (len >= 3) {
      ans += len - 2;
    }
    i = j;
  }
  cout << ans << endl;
  return 0;
}

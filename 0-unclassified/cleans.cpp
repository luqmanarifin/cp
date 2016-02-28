#include <bits/stdc++.h>

using namespace std;

string s[105];

int main() {
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> s[i];
  }
  sort(s, s + n);
  int ans = 0;
  for(int i = 0; i < n; ) {
    int j = i + 1;
    while(j < n && s[j] == s[j - 1]) {
      j++;
    }
    ans = max(ans, j - i);
    i = j;
  }
  cout << ans << endl;
  return 0;
}

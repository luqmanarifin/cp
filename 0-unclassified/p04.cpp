#include <bits/stdc++.h>

using namespace std;

char s[55];

int main() {
  int n;
  scanf("%d %s", &n, s);
  int ans = 0;
  for(int i = 1; i < n; i++) {
    if(s[i] == 'L' && s[i - 1] == 'R') {
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}

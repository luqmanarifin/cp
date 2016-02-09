#include <bits/stdc++.h>

using namespace std;

char s[105];

int main() {
  scanf("%s", s);
  int n = strlen(s);
  int ans = 0;
  for(int i = 0; i < n; i++) {
    if(i % 3 == 0) {
      ans += s[i] != 'S';
    } else if(i % 3 == 1) {
      ans += s[i] != 'O';
    } else {
      ans += s[i] != 'S';
    }
  }
  cout << ans << endl;
  return 0;
}

#include <bits/stdc++.h>

using namespace std;

int n, m;
char s[(int)1e6 + 5];

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    scanf("%d %d %s", &n, &m, s);
    int ans = 0;
    for(int i = 1; i < m; i++) {
      if(s[i] != s[i - 1]) ans++;
    }
    cout << ans << endl;
  }
  return 0;
}

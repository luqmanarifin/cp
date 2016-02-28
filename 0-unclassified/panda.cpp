#include <bits/stdc++.h>

using namespace std;

bool done[26];
char s[500];

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    scanf("%s", s);
    int n = strlen(s);
    memset(done, 0, sizeof(done));
    int ans = 0;
    for(int i = 0; i < n; i++) {
      if(!done[s[i] - 'a']) ans++;
      done[s[i] - 'a'] = 1;
    }
    cout << ans << endl;
  }
  
  return 0;
}

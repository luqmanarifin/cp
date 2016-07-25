#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

char s[N];
bool done[256];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    memset(done, 0, sizeof(done));
    
    scanf("%s", s);
    int n = strlen(s);
    int ans = 0;
    for (int i = 0; i < n; i++) {
      if (done[s[i]]) continue;
      done[s[i]]++;
      ans++;
    }
    cout << ans << endl;
  }

  return 0;
}

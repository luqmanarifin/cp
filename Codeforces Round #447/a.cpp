
#include <bits/stdc++.h>

using namespace std;

const int N = 105;

char s[N];

int main() {
  scanf("%s", s);
  int n = strlen(s);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      for (int k = j + 1; k < n; k++) {
        if (s[i] == 'Q' && s[j] == 'A' && s[k] == 'Q') {
          ans++;
        }
      }
    }
  }
  cout << ans << endl;

  return 0;
}


#include <bits/stdc++.h>

using namespace std;

const int N = 105;

string a[N];

int main() {
  string s;
  int n;
  cin >> s >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) {
    if (a[i] == s) {
      puts("YES");
      return 0;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (a[i][1] == s[0] && a[j][0] == s[1]) {
        puts("YES");
        return 0;
      }
    }
  }
  puts("NO");
  return 0;
}

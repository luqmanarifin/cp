#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

char s[N];

int main() {
  int n;
  scanf("%d %s", &n, s);
  int ans = 0;
  int one = 0, zero = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '1') {
      one++;
    } else if (s[i] == '0') {
      zero++;
    } else {
      ans++;
    }
  }
  if (one == 0 && zero == 0) {
    puts("-1");
  } else if (one == 0) {
    printf("%d\n", ans + zero - 1);
  } else {
    for (int i = 0; i < n; i++) {
      if (s[i] == '1') break;
      if (s[i] == '0') ans++;
    }
    cout << ans << endl;
  }
  return 0;
}

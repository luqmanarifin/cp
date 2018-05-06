
#include <bits/stdc++.h>

using namespace std;

int main() {
  int a = 0, b = 0, n;
  scanf("%d", &n);
  while (n--) {
    int v;
    scanf("%d", &v);
    if (v == 1) {
      a++;
    } else {
      b++;
    }
  }
  int ans = 0;
  for (int i = 0; i <= b; i++) {
    if (a < i) break;
    ans = max(ans, i + (a - i) / 3);
  }
  cout << ans << endl;
  
  return 0;
}

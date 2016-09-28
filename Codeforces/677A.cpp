#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

int main() {
  int n, h;
  scanf("%d %d", &n, &h);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int v;
    scanf("%d", &v);
    if (v > h) {
      ans += 2;
    } else {
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}

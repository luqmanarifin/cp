#include <bits/stdc++.h>

using namespace std;

int a[105];

int main() {
  int v1, v2, t, d;
  scanf("%d %d %d %d", &v1, &v2, &t, &d);
  int ans = v1 + v2;
  if(v1 > v2) swap(v1, v2);
  t -= 2;
  while(t--) {
    if(v1 < v2) {
      v1 += d;
      ans += v1;
    } else {
      v2 += d;
      ans += v2;
    }
  }
  cout << ans << endl;
  return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main() {
  int ans = 0, now = 1, bef = 1, a, b;
  scanf("%d %d", &a, &b);
  while(now <= b) {
    if(a <= now) ans++;
    swap(bef, now);
    now += bef;
  }
  cout << ans << endl;
  return 0;
}

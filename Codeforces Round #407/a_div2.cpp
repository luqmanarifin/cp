#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N];

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int v;
    scanf("%d", &v);
    ans += v / k + (v % k? 1 : 0);
  }
  ans = (ans + 1) / 2;
  cout << ans << endl;
  return 0;
}

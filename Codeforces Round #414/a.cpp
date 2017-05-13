#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int v[N];

int main() {
  int a, b, c, n;
  scanf("%d %d %d %d", &a, &b, &c, &n);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", v + i);
    if (b < v[i] && v[i] < c) {
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}

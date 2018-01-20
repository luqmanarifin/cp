#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

bool is[N];

int main() {
  for (int i = 0; i <= 1000; i++) is[i * i] = 1;
  int ans = -1e7;
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int v;
    scanf("%d", &v);
    if (v < 0) {
      ans = max(ans, v);
    } else if (!is[v]) {
      ans = max(ans, v);
    }
  }
  cout << ans << endl;
  return 0;
}

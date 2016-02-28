#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

char a[N], b[N];

int main() {
  int n;
  scanf("%d", &n);
  scanf("%s %s", a, b);
  int ans = 0;
  for(int i = 0; i < n; i++) {
    int maxi = max(a[i], b[i]);
    int mini = min(a[i], b[i]);
    ans += min(maxi - mini, 10 - (maxi - mini));
  }
  cout << ans << endl;
  return 0;
}

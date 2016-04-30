#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int a[N], ans[N];

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) scanf("%d", a + i);
  fill(ans, ans + N, N);
  ans[0] = 0;
  for(int i = 0; i < n; i++) {
    if(a[i]) continue;
    for(int j = 1; j <= 2; j++) {
      ans[i + j] = min(ans[i + j], ans[i] + 1);
    }
  }
  cout << ans[n - 1] << endl;
  return 0;
}
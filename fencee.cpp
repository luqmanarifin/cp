#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
const int inf = 2e9;

int a[N];

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  for(int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  int now = 0;
  int ans = 0;
  for(int i = 0; i < k; i++) {
    now += a[i];
  }
  int mini = now;
  for(int i = 1; i + k <= n; i++) {
    now -= a[i - 1];
    now += a[i + k - 1];
    if(now < mini) {
      mini = now;
      ans = i;
    }
  }
  cout << ans + 1 << endl;
  return 0;
}


#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

int a[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  int ans = 0;
  for (int i = 1; i + 1 < n; i++) {
    if (a[i - 1] < a[i] && a[i] > a[i + 1]) {
      ans++;
    }
    if (a[i - 1] > a[i] && a[i] < a[i + 1]) {
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}

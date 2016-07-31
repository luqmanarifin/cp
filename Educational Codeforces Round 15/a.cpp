#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N];

int main() {
  int n;
  int ans = 0, bef = -1, now = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
    if (a[i] > bef) {
      now++;
      ans = max(ans, now);
      bef = a[i];
    } else {
      now = 1;
      ans = max(ans, now);
      bef = a[i];
    }  
  }
  cout << ans << endl;
  return 0;
}

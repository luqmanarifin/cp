
#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int a[N];

int main() {
  int n;
  scanf("%d", &n);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
    bool lucky = 1;
    for (int j = 0; j < i; j++) {
      if (a[j] >= a[i]) lucky = 0;
    }
    if (lucky) ans++;
  }
  cout << ans << endl;
  return 0;
}

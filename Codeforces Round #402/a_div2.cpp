#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int a[N], b[N], cnt[N], cnta[N], cntb[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
    cnt[a[i]]++;
    cnta[a[i]]++;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", b + i);
    cnt[b[i]]++;
    cntb[b[i]]++;
  }
  for (int i = 1; i <= 5; i++) {
    if (cnt[i] % 2) {
      puts("-1");
      return 0;
    }
  }
  int ans = 0;
  for (int i = 1; i <= 5; i++) {
    ans += abs(cnta[i] - cntb[i]) / 2;
  }
  cout << ans / 2 << endl;
  return 0;
}


#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int h[N], cnt[N];

int main() {
  int n;
  scanf("%d", &n);
  cnt[0] = 1;
  for (int i = 2; i <= n; i++) {
    int v;
    scanf("%d", &v);
    h[i] = h[v] + 1;
    cnt[h[i]]++;
  }
  int ans = 0;
  for (int i = 0; i < N; i++) if (cnt[i] % 2) ans++;
  cout << ans << endl;
  return 0;
}

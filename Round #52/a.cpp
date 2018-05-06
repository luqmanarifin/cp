
#include <bits/stdc++.h>

using namespace std;

const int N = 5005;

int cnt[N];
int a[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", a + i), cnt[a[i]]++;
  long long ans = 0;
  ans += 1LL * cnt[0] * (cnt[0] - 1) * (cnt[0] - 2) / 6;
  for (int i = 1; i < N; i++) {
    // 0 + i
    ans += 1LL * cnt[0] * cnt[i] * (cnt[i] - 1) / 2;
    for (int j = 1; j + j < i; j++) {
      ans += 1LL * cnt[i] * cnt[j] * cnt[i - j];
    }
    // j + j == i
    if (i % 2 == 0) {
      int j = i / 2;
      ans += 1LL * cnt[i] * cnt[j] * (cnt[j] - 1) / 2;
    }
  }
  cout << ans << endl;
  return 0;
}

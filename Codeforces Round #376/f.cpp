#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;

int a[N];
int cnt[N];

int find(int l, int r) {
  return cnt[r] - cnt[l - 1];
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
    cnt[a[i]]++;
  }
  for (int i = 1; i < N; i++) cnt[i] += cnt[i - 1];
  long long ans = 0;
  for (int i = 1; i < N; i++) {
    if (find(i, i) == 0) continue;
    long long cur = 0;
    for (int j = i; j + i < N; j += i) {
      cur += 1LL * find(j, j + i - 1) * j;
    }
    ans = max(ans, cur);
  }
  cout << ans << endl;
  return 0;
}

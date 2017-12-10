#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int cnt[N];

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; i++) {
    int v;
    scanf("%d", &v);
    cnt[v]++;
  }
  vector<int> all;
  for (int i = 0; i < N; i++) {
    if (cnt[i]) {
      all.push_back(cnt[i]);
    }
  }
  sort(all.begin(), all.end());
  reverse(all.begin(), all.end());
  int ans = 0;
  for (int i = k; i < all.size(); i++) ans += all[i];
  cout << ans << endl;
  return 0;
}

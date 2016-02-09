#include <bits/stdc++.h>

using namespace std;

int cnt[15];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; i++) {
    int v;
    scanf("%d", &v);
    cnt[v]++;
  }
  int ans = 0;
  for(int i = 1; i <= 10; i++) {
    for(int j = i + 1; j <= 10; j++) {
      ans += cnt[i] * cnt[j];
    }
  }
  cout << ans << endl;
  return 0;
}

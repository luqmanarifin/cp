#include <bits/stdc++.h>

using namespace std;

int cnt[105];

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  for(int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    cnt[a]++;
  }
  int ans = 0;
  for(int i = 0; i < 105; i++) {
    if(cnt[i] > n / k) {
      ans += cnt[i] - n / k;
    }
  }
  cout << ans << endl;
  return 0;
}

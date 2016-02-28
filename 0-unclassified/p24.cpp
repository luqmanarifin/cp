#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  int sum = 0, ans = 0;
  for(int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    sum += a;
    if(sum > 0) ans++;
    sum = max(0, sum - k);
  }
  ans += sum / k + (sum % k? 1 : 0);
  cout << ans << endl;
  return 0;
}

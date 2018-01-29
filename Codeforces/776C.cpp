#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N];
long long s[N];
map<long long, int> mp;

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
    s[i] += s[i - 1] + a[i];
  }
  mp[0] = 1;
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    long long sum = 1;
    while (abs(sum) <= 1e14) {
      ans += mp[s[i] - sum];
      sum *= k;
      if (k == 1 && sum == 1) break;
      if (k == -1 && sum == 1) break;
    }
    mp[s[i]]++;
  }
  cout << ans << endl;
  return 0;
}

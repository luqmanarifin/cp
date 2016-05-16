#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 1e6 + 5;
const int mod = 1e9 + 7;

int s[N];
bool done[16];

int find(int n) {
  vector<int> a;
  while(n > 0) {
    a.push_back(n % 10);
    n /= 10;
  }
  reverse(a.begin(), a.end());
  memset(done, 0, sizeof(done));
  int ans = 0;
  for(int i = 0; i < a.size(); i++) {
    int val = 0;
    for(int j = i; j < a.size(); j++) {
      val ^= a[j];
      if(!done[val]) {
        ans += val;
        done[val] = 1;
      }
    }
  }
  return ans;
}

main() {
  for(int i = 1; i < N; i++) {
    s[i] = (s[i - 1] + find(i)) % mod;
  }
  cout << s[121] << endl;
  int t;
  scanf("%lld", &t);
  while(t--) {
    int l, r;
    scanf("%lld %lld", &l, &r);
    int ans = (s[r] - s[l - 1] + mod) % mod;
    printf("%lld\n", ans);
  }
  return 0;
}
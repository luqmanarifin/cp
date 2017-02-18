#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const long long mod = 1e9 + 7;

int a[N];
map<int, int> mp;

struct BIT {
  BIT() {
    memset(bit, 0, sizeof(bit));
  }
  
  void add(int i, long long val) {
    for (; i < N; i |= i + 1) {
      bit[i] += val;
      bit[i] %= mod;
    }
  }
  
  void reset() {
    memset(bit, 0, sizeof(bit));
  }
  
  long long find(int i) {
    long long ret = 0;
    for (; i >= 0; i = (i & (i + 1)) - 1) {
      ret += bit[i];
      ret %= mod;
    }
    return ret;
  }
  
  long long bit[N];
};

long long power(long long a, long long b) {
  if (b == 0) return 1;
  long long tmp = power(a, b / 2);
  tmp = tmp * tmp % mod;
  if (b & 1) {
    tmp = tmp * a % mod;
  }
  return tmp;
}

long long dp[N][3];
long long cnt[N][3];

int main() {
  int n;
  scanf("%d", &n);
  vector<int> num;
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
    num.push_back(a[i]);
  }
  sort(num.begin(), num.end());
  num.resize(distance(num.begin(), unique(num.begin(), num.end())));
  for (int i = 0; i < num.size(); i++) mp[num[i]] = i;
  for (int i = 0; i < n; i++) a[i] = 1 + mp[a[i]];
  //for (int i = 0; i < n; i++) printf("%d ", a[i]); printf("\n");
  
  BIT u, v;
  for (int i = 0; i < N; i++) cnt[i][0] = 1;
  long long cur = 0;
  for (int i = 0; i < n; i++) {
    dp[i][0] = cnt[a[i]][0];
    dp[i][1] = (u.find(a[i] - 1) + cnt[a[i]][1]) % mod;
    dp[i][2] = (v.find(N - a[i] - 1) + cnt[a[i]][2]) % mod;
    
    u.add(a[i], (dp[i][1] + cnt[a[i]][0]) % mod);
    v.add(N - a[i], (dp[i][2] + cnt[a[i]][0]) % mod);
    cnt[a[i]][0] = cnt[a[i]][0] * 2;
    cnt[a[i]][1] += dp[i][1];
    cnt[a[i]][2] += dp[i][2];
    
    for (int j = 0; j < 3; j++) {
      cnt[a[i]][j] %= mod;
      //printf("%d ", dp[i][j]);
      cur += dp[i][j];
      cur %= mod;
    }
    //printf("\n");
  }
  long long ans = (power(2, n) - cur - 1) % mod;
  if (ans < 0) ans += mod;
  cout << ans << endl;
  return 0;
}

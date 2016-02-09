#include <bits/stdc++.h>

using namespace std;

const long long inf = 1e17;

set<long long> s;
vector<long long> v;
vector<long long> dp[30];
long long lim;
long long a[30];

int id(long long a) {
  return lower_bound(v.begin(), v.end(), a) - v.begin();
}

long long fact(long long a) {
  long long ret = 1;
  for(int i = 1; i <= a; i++) {
    ret *= i;
    if(lim < ret) return inf;
  }
  return ret;
}

int main() {
  s.insert(0);
  int n, k;
  scanf("%d %d %I64d", &n, &k, &lim);
  for(int i = 0; i < n; i++) {
    scanf("%I64d", a + i);
    long long f = fact(a[i]);
    set<long long> temp;
    for(auto it : s) {
      if(it + a[i] <= lim) {
        temp.insert(it + a[i]);
      }
      if(it + f <= lim) {
        temp.insert(it + f);
      }
    }
    for(auto it : temp) {
      s.insert(it);
    }
  }
  for(auto it : s) {
    v.push_back(it);
  }
  for(int i = 0; i < 30; i++) {
    dp[i].resize(v.size());
  }
  dp[0][id(0)] = 1;
  for(int i = 0; i < n; i++) {
    long long f = fact(a[i]);
    for(int j = v.size() - 1; j >= 0; j--) {
      long long ba = v[j] + a[i];
      long long bf = v[j] + f;
      int ida = id(ba);
      int idf = id(bf);
      for(int flag = k; flag >= 0; flag--) {
        if(ba <= lim) {
          dp[flag][ida] += dp[flag][j];
        }
        if(bf <= lim) {
          dp[flag + 1][idf] += dp[flag][j];
        }
      }
    }
  }
  int goal = id(lim);
  long long ans = 0;
  for(int i = 0; i <= k; i++) {
    ans += dp[i][goal];
  }
  cout << ans << endl;
  return 0;
}

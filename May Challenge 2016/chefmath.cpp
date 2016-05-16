#include <bits/stdc++.h>

using namespace std;

const int MID = 22;
const int N = 19;
const long long mod = 1e9 + 7;
const int lim = 1e9 + 5;

vector<int> f;
map<long long, long long> lo[11], hi[11];

long long init(int mid) {
  for(int i = 0; i < 11; i++) {
    lo[i].clear();
    hi[i].clear();
  }
  lo[0][0] = 1;
  for(int p = 0; p < mid; p++) {
    for(int i = 0; i < 10; i++) {
      for(auto it : lo[i]) {
        if(it.first > lim) break;
        long long to = it.first + f[p];
        lo[i + 1][to] = (lo[i + 1][to] + it.second) % mod;
      }
    }
  }
  hi[0][0] = 1;
  for(int p = mid; p < f.size(); p++) {
    for(int i = 0; i < 10; i++) {
      for(auto it : hi[i]) {
        if(it.first > lim) break;
        long long to = it.first + f[p];
        hi[i + 1][to] = (hi[i + 1][to] + it.second) % mod;
      }
    }
  }
  long long ans = 0;
  for(int i = 0; i <= 10; i++) {
    ans += lo[i].size() + hi[i].size();
  }
  return ans;
}

int main() {
  int a = 1, b = 2;
  f = {1, 2};
  while(a + b <= 1e9) {
    f.push_back(a + b);
    int c = a + b;
    a = b;
    b = c;
  }
  
  init(MID);
  
  int t;
  scanf("%d", &t);
  while(t--) {
    int n, k;
    scanf("%d %d", &n, &k);
    long long ans = 0;
    for(int i = 0; i <= k; i++) {
      if(lo[i].size() < hi[k - i].size()) {
        for(auto it : lo[i]) {
          if(!hi[k - i].count(n - it.first)) continue;
          ans += it.second * hi[k - i][n - it.first];
          ans %= mod;
        }
      } else {
        for(auto it : hi[k - i]) {
          if(!lo[i].count(n - it.first)) continue;
          ans += it.second * lo[i][n - it.first];
          ans %= mod;
        }
      }
    }
    cout << ans << endl;
  }
  
  return 0;
}
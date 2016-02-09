#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

vector<int> prime;
vector<int> dp;
bool is[N];
vector<int> factors[N];

int main() {
  for(int i = 2; i < N; i++) {
    if(!is[i]) {
      prime.push_back(i);
      for(long long j = i; j < N; j += i) {
        factors[j].push_back(prime.size() - 1);
        is[j] = 1;
      }
    }
  }
  dp.assign(prime.size(), 0);

  int n;
  scanf("%d", &n);
  while(n--) {
    int a, maxi = 0;
    scanf("%d", &a);
    for(auto it : factors[a]) {
      maxi = max(maxi, dp[it]);
    }
    for(auto it : factors[a]) {
      dp[it] = maxi + 1;
    }
  }
  int ans = 1;
  for(auto it : dp) {
    ans = max(ans, it);
  }
  cout << ans << endl;
  return 0;
}

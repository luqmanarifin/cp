#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

bitset<N> is;
vector<int> prime;

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for(int i = 2; i <= n; i++) {
    if(!is[i]) {
      prime.push_back(i);
      for(long long j = 1LL*i*i; j <= n; j += i) {
        is[j] = 1;
      }
    }
  }
  int sz = (int) prime.size();
  long long ans = 0;
  for(int i = 2; i <= n; i++) {
    int id = lower_bound(prime.begin(), prime.end(), i) - prime.begin();
    if(id + m <= sz) {
      ans += n - prime[id + m - 1] + 1;
    }
  }
  cout << ans << endl;
  return 0;
}
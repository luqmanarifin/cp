#include <bits/stdc++.h>

using namespace std;

const int N = 30;

int a[N];

int main() {
  ios_base::sync_with_stdio(0);
  
  int t;
  cin >> t;
  while(t--) {
    long long n, p;
    cin >> n >> p;
    for(int i = 0; i < p; i++) {
      cin >> a[i];
    }
    sort(a, a + p);
    vector<pair<long long, int>> num;
    num.emplace_back(1, a[0]);
    for(int i = 1; i < p; i++) {
      vector<pair<long long, int>> to;
      to.emplace_back(1, a[i]);
      for(auto it : num) {
        if(it.second <= n / a[i] + 1) {
          to.emplace_back(it.first + 1, it.second * a[i]);
        }
      }
      for(auto it : to) {
        num.push_back(it);
      }
    }
    long long ans = 0;
    for(auto it : num) {
      //cout << it.first << ' ' << it.second << endl;
      long long prime = it.second;
      int cnt = it.first;
      ans += (cnt % 2? n / prime : -n / prime) * (1LL << (cnt - 1));
    }
    cout << ans << endl;
  }
  
  return 0;
}

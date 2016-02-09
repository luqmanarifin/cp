#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

long long a[N];

int main() {
  int t;
  scanf("%d", &t);
  for(int tt = 1; tt <= t; tt++) {
    long long l, n, m, d;
    scanf("%I64d %I64d %I64d %I64d", &l, &n, &m, &d);
    for(int i = 0; i < n; i++) {
      scanf("%I64d", a + i);
    }
    m = min(m, l);
    
    // will be done, duration
    multiset<pair<long long, long long>> was;
    vector<long long> washed;
    for(int i = 0; i < n; i++) {
      was.insert(make_pair(a[i], a[i]));
    }
    for(int i = 0; i < l; i++) {
      auto it = was.begin();
      washed.push_back(it->first);
      pair<long long, long long> will = {it->first + it->second, it->second};
      was.erase(it);
      was.insert(will);
    }
    sort(washed.begin(), washed.end());
    
    long long ans = 0;
    multiset<long long> dry;
    for(int i = 0; i < m; i++) {
      dry.insert(0);
    }
    for(auto w : washed) {
      auto it = dry.begin(); 
      long long will = max(*it, w) + d;
      dry.erase(it);
      dry.insert(will);
      ans = max(ans, will);
    }
    printf("Case #%d: %I64d\n", tt, ans);
    cerr << tt << " done!" << endl;
  }
  
  return 0;
}

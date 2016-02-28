#include <bits/stdc++.h>

using namespace std;

inline int lcm(int a, int b) {
  return a / __gcd(a, b) * b;
}

int mk[1005];

int main() {
  int t;
  scanf("%d", &t);
  for(int tt = 1; tt <= t; tt++) {
    int n, b;
    scanf("%d %d", &b, &n);
    int kpk = 1;
    for(int i = 1; i <= b; i++) {
      scanf("%d", &mk[i]);
      kpk = lcm(kpk, mk[i]);
    }
    vector<pair<int,int>> q;
    for(int i = 1; i <= b; i++) {
      for(int j = 0; j < kpk; j += mk[i]) {
        q.emplace_back(j, i);
      }
    }
    n--;
    n %= q.size();
    sort(q.begin(), q.end());
    printf("Case #%d: %d\n", tt, q[n].second);
  }
  
  return 0;
}

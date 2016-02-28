#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    int n, m, q;
    scanf("%d %d %d", &n, &m, &q);
    vector<int> a, b;
    a.push_back(1);
    a.push_back(n);
    b.push_back(1);
    b.push_back(m);
    while(q--) {
      int u, v;
      scanf("%d %d", &u, &v);
      a.push_back(u);
      b.push_back(v);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    a.resize(distance(a.begin(), unique(a.begin(), a.end())));
    b.resize(distance(b.begin(), unique(b.begin(), b.end())));
    int mka = -1, mna = 1e9, mkb = -1, mnb = 1e9;
    for(int i = 1; i < a.size(); i++) {
      mka = max(mka, a[i] - a[i - 1]);
      mna = min(mna, a[i] - a[i - 1]);
    }
    for(int i = 1; i < b.size(); i++) {
      mkb = max(mkb, b[i] - b[i - 1]);
      mnb = min(mnb, b[i] - b[i - 1]);
    }
    printf("%lld %lld %lld\n", 1LL*(a.size() - 1)*(b.size() - 1), 1LL*mna*mnb, 1LL*mka*mkb);
  }
  
  return 0;
}

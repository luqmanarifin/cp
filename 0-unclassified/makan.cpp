#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  for(int tt = 1; tt <= t; tt++) {
    int n, m, r;
    scanf("%d %d %d", &n, &m, &r);
    multiset<int> s;
    for(int i = 0; i < n; i++) {
      int a;
      scanf("%d", &a);
      s.insert(a);
    }
    
    int ans = 0;
    while(m <= r) {
      auto it = s.lower_bound(m);
      if(it == s.begin()) {
        break;
      }
      it--;
      m += *it;
      s.erase(it);
      ans++;
    }
    printf("Kasus #%d: ", tt);
    if(m > r) {
      printf("%d\n", ans);
    } else {
      puts("UTS!");
    }
  }
  
  return 0;
}

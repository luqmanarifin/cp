#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

int a[N], b[N];
multiset<int> s;

int main() {
  int q;
  scanf("%d", &q);
  int l = 0, r = 0;
  while(q--) {
    int t;
    scanf("%d", &t);
    if(t == 1) {
      int u, v;
      scanf("%d %d", &u, &v);
      a[r] = u;
      b[r] = v;
      s.insert(a[r]);
      r++;
    } else {
      int now;
      scanf("%d", &now);
      while(l < r && b[l] <= now - 60) {
        s.erase(s.find(a[l]));
        l++;
      }
      if(l == r) {
        puts("-1");
      } else {
        auto it = s.end();
        it--;
        printf("%d\n", *it);
      }
    }
  }
  
  return 0;
}
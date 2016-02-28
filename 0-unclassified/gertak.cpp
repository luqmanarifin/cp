#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  for(int tt = 1; tt <= t; tt++) {
    int d;
    scanf("%d", &d);
    set<int> belum, ada;
    printf("Case #%d:\n", tt);
    for(int it = 0; it < d; it++) {
      int n, m;
      vector<int> an, am;
      scanf("%d", &m);
      for(int i = 0; i < m; i++) {
        int a;
        scanf("%d", &a);
        if(!ada.count(a)) {
          belum.insert(a);
        }
      }
      
      scanf("%d", &n);
      for(int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        an.push_back(a);
      }

      for(auto it : an) {
        ada.insert(it);
        if(belum.count(it)) {
          belum.erase(it);
        }
      }
      puts(belum.empty()? "SAFE" : "ALERT");
    }
  }
  
  return 0;
}

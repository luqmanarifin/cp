#include <bits/stdc++.h>

using namespace std;

const int N = 105;
const long long inf = 1e18;

priority_queue<int> pq[N];

int main() {
  int t;
  scanf("%d", &t);
  for(int tt = 1; tt <= t; tt++) {
    printf("Case #%d:\n", tt);
    for(int i = 0; i <= 100; i++) {
      while(!pq[i].empty()) pq[i].pop();
    }
    
    int n;
    scanf("%d", &n);
    while(n--) {
      char ct;
      scanf(" %c", &ct);
      if(ct == 'P') {
        int s0, t0, r;
        scanf("%d %d %d", &t0, &s0, &r);
        pq[r].push(s0 - t0 * r);
      } else {
        int at;
        scanf("%d", &at);
        long long maxi = -inf, p = -1;
        for(int i = 100; i >= 0; i--) {
          if(!pq[i].empty()) {
            long long cur = pq[i].top() + 1LL * i * at;
            if(cur > maxi) {
              maxi = cur;
              p = i;
            }
          }
        }
        pq[p].pop();
        printf("%lld %d\n", maxi, p);
      }
    }
  }
  
  return 0;
}

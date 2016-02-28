#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

int is[N];

int main() {
  int t;
  scanf("%d", &t);
  for(int tt = 1; tt <= t; tt++) {
    int n, p;
    scanf("%d %d", &n, &p);
    vector<int> num, rem;
    for(int i = 0; i < p; i++) {
      int a;
      scanf("%d", &a);
      if(a * a <= n) {
        num.push_back(a);
      } else {
        rem.push_back(a);
      }
    }
    int ans = 0;
    for(int mask = 0; mask < (1 << num.size()); mask++) {
      for(int i = 1; i <= n; i++) {
        is[i] = 0;
      }
      for(int i = 0; i < num.size(); i++) {
        if(mask & (1 << i)) {
          for(int j = num[i]; j <= n; j += num[i]) {
            is[j] ^= 1;
          }
        }
      }
      for(int i = 0; i < rem.size(); i++) {
        int cnt = 0, lom = 0;
        for(int j = rem[i]; j <= n; j += rem[i]) {
          cnt++;
          if(!is[j]) {
            lom++;
          }
        }
        if(lom > cnt - lom) {
          for(int j = rem[i]; j <= n; j += rem[i]) {
            is[j] ^= 1;
          }
        }
      }
      int cur = 0;
      for(int i = 1; i <= n; i++) {
        if(is[i]) {
          cur++;
        }
      }
      ans = max(ans, cur);
    }
    printf("Case #%d: %d\n", tt, ans);
  }
  return 0;
}

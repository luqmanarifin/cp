#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 1e4 + 5;
const int inf = 2e9;
 
bool is[N];
vector<int> p;
int a[N];
 
int main() {
  for(int i = 2; i < N; i++) {
    if(!is[i]) {
      p.push_back(i);
      for(int j = i * i; j < N; j += i) {
        is[j] = 1;
      }
    }
  }
  int t;
  scanf("%d", &t);
  while(t--) {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
      scanf("%d", a + i);
    }
    int ans = inf;
    for(auto it : p) {
      int cur = 0;
      int now = 0;
      for(int i = 0; i < n; i++) {
        if(a[i] > now) now = a[i];
        int b = now / it;
        if(now % it) b++;
        now = b * it;
        cur += now - a[i];
        if(cur > ans) break;
      }
      ans = min(ans, cur);
    }
    printf("%d\n", ans);
  }
  return 0;
}
 
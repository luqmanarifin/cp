#include <bits/stdc++.h>

using namespace std;

const int N = 55;

int ans[N];
int a[N];

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    int n, sum = 0;
    scanf("%d", &n);
    priority_queue<pair<int, int>> pq;
    
    for(int i = 1; i <= n; i++) {
      scanf("%d", a + i);
      sum += a[i];
      pq.emplace(a[i], i);
    }
    if(sum != n) {
      puts("-1");
      continue;
    }
    
    memset(ans, 0, sizeof(ans));
    while(!pq.empty()) {
      int sc, now;
      tie(sc, now) = pq.top();
      pq.pop();
      if(a[now] != sc || ans[now]) {
        continue;
      }
      int maxi = -1, pos = -1;
      for(int i = 1; i <= n; i++) {
        if(i == now) continue;
        if(a[i] > maxi && a[i] > 0) {
          maxi = a[i];
          pos = i;
        }
      }
      if(maxi == -1) {
        break;
      }
      ans[now] = pos;
      a[pos]--;
      pq.emplace(a[pos], pos);
    }
    bool zero = 0;
    for(int i = 1; i <= n; i++) {
      if(ans[i] == 0) {
        zero = 1;
        break;
      }
    }
    if(zero) {
      puts("-1");
      continue;
    }
    for(int i = 1; i <= n; i++) {
      printf("%d ", ans[i]);
    }
    printf("\n");
    next:;
  }
  
  return 0;
}

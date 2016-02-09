#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int cnt[N];

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    int n;
    scanf("%d", &n);
    memset(cnt, 0, sizeof(cnt));
    for(int i = 0; i < n; i++) {
      int a;
      scanf("%d", &a);
      cnt[a]++;
    }
    int ans = 1e9;
    for(int i = 0; i < N; i++) {
      ans = min(ans, n - cnt[i]);
    }
    printf("%d\n", ans);
  }
  
  return 0;
}
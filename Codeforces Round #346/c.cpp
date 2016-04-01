#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 1e5 + 5;

int a[N];

long long sum(int n) {
  return 1LL * n * (n + 1) / 2;
}

long long sum(int l, int r) {
  if(l > r) return 0;
  return sum(r) - sum(l - 1);
}

main() {
  int n;
  long long m;
  scanf("%I64d %I64d", &n, &m);
  for(int i = 1; i <= n; i++) {
    scanf("%I64d", a + i);
  }
  sort(a + 1, a + 1 + n);
  a[n + 1] = 1000000001;
  vector<int> ans;
  for(int i = 0; i <= n; i++) {
    int l = a[i];
    int r = a[i + 1] - 1;
    while(l < r) {
      int mid = (l + r + 1) >> 1;
      if(sum(a[i] + 1, mid) <= m) {
        l = mid;
      } else {
        r = mid - 1;
      }
    }
    for(int j = a[i] + 1; j <= r; j++) {
      ans.push_back(j);
      m -= j;
    }
  }
  printf("%d\n", ans.size());
  for(auto it : ans) printf("%I64d ", it);
  return 0;
}

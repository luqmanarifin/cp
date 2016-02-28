#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int ans[N];
int a[N];

int get(int l, int r) {
  return r - l + 1;
}

void solve(int l, int r) {
  if(l == r) {
    ans[1] = max(ans[1], a[l]);
    return;
  }
  int mid = (l + r) >> 1;
  solve(l, mid);
  solve(mid + 1, r);
  int ll = mid, rr = mid + 1;
  int now = min(a[ll], a[rr]);
  ans[2] = max(ans[2], now);
  while(ll != l || rr != r) {
    int lef = 0, rig = 0;
    if(l < ll) lef = min(now, a[ll - 1]);
    if(rr < r) rig = min(now, a[rr + 1]);
    if(lef > rig) {
      ll--;
      int cnt = get(ll, rr);
      now = lef;
      ans[cnt] = max(ans[cnt], now);
    } else {
      rr++;
      int cnt = get(ll, rr);
      now = rig;
      ans[cnt] = max(ans[cnt], now);
    }
    //if(ans[4] == 4) printf("%d %d %d %d\n", l, ll, rr, r);
  }
}

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  solve(0, n - 1);
  for(int i = 1; i <= n; i++) {
    printf("%d ", ans[i]);
  }
  
  return 0;
}

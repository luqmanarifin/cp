#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const long long inf = 1e18;

long long l_ev_min[N];
long long l_ev_max[N];

long long l_od_min[N];
long long l_od_max[N];

long long r_ev_min[N];
long long r_ev_max[N];

long long r_od_min[N];
long long r_od_max[N];

long long l_min[N], l_max[N];
long long r_min[N], r_max[N];

int a[N];

void upd_min(long long& at, long long val) {
  at = min(at, val);
}

void upd_max(long long& at, long long val) {
  at = max(at, val);
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    for (int i = 0; i < N; i++) {
      l_ev_min[i] = inf;
      l_od_min[i] = inf;
      r_ev_min[i] = inf;
      r_od_min[i] = inf;
      l_min[i] = inf;
      r_min[i] = inf;
    }
    for (int i = 0; i < N; i++) {
      l_ev_max[i] = -inf;
      l_od_max[i] = -inf;
      r_ev_max[i] = -inf;
      r_od_max[i] = -inf;
      l_max[i] = -inf;
      r_max[i] = -inf;
    }
    for (int i = 1; i <= n; i++) {
      upd_min(l_od_min[i], a[i]);
      upd_max(l_od_max[i], a[i]);
      
      if (abs(l_ev_min[i-1]) != inf) upd_min(l_od_min[i], l_ev_min[i-1] + a[i]);
      if (abs(l_ev_max[i-1]) != inf) upd_min(l_od_min[i], l_ev_max[i-1] + a[i]);
      if (abs(l_ev_min[i-1]) != inf) upd_max(l_od_max[i], l_ev_min[i-1] + a[i]);
      if (abs(l_ev_max[i-1]) != inf) upd_max(l_od_max[i], l_ev_max[i-1] + a[i]);
      
      if (abs(l_od_min[i-1]) != inf) upd_min(l_ev_min[i], l_od_min[i-1] - a[i]);
      if (abs(l_od_max[i-1]) != inf) upd_min(l_ev_min[i], l_od_max[i-1] - a[i]);
      if (abs(l_od_min[i-1]) != inf) upd_max(l_ev_max[i], l_od_min[i-1] - a[i]);
      if (abs(l_od_max[i-1]) != inf) upd_max(l_ev_max[i], l_od_max[i-1] - a[i]);      
    }
    
    for (int i = n; i >= 1; i--) {
      upd_min(r_od_min[i], a[i]);
      upd_max(r_od_max[i], a[i]);
      
      if (abs(r_ev_min[i+1]) != inf) upd_min(r_od_min[i], -r_ev_min[i+1] + a[i]);
      if (abs(r_ev_max[i+1]) != inf) upd_min(r_od_min[i], -r_ev_max[i+1] + a[i]);
      if (abs(r_ev_min[i+1]) != inf) upd_max(r_od_max[i], -r_ev_min[i+1] + a[i]);
      if (abs(r_ev_max[i+1]) != inf) upd_max(r_od_max[i], -r_ev_max[i+1] + a[i]);
      
      if (abs(r_od_min[i+1]) != inf) upd_min(r_ev_min[i], -r_od_min[i+1] + a[i]);
      if (abs(r_od_max[i+1]) != inf) upd_min(r_ev_min[i], -r_od_max[i+1] + a[i]);
      if (abs(r_od_min[i+1]) != inf) upd_max(r_ev_max[i], -r_od_min[i+1] + a[i]);
      if (abs(r_od_max[i+1]) != inf) upd_max(r_ev_max[i], -r_od_max[i+1] + a[i]);
    }
    
    for (int i = 1; i <= n; i++) {
      l_min[i] = l_min[i - 1];
      l_max[i] = l_max[i - 1];
      
      upd_min(l_min[i], l_od_min[i]);
      upd_min(l_min[i], l_ev_min[i]);
      upd_max(l_max[i], l_od_max[i]);
      upd_max(l_max[i], l_ev_max[i]);
    }
    
    for (int i = n; i >= 1; i--) {
      r_min[i] = r_min[i + 1];
      r_max[i] = r_max[i + 1];
      
      upd_min(r_min[i], r_od_min[i]);
      upd_min(r_min[i], r_ev_min[i]);
      upd_max(r_max[i], r_od_max[i]);
      upd_max(r_max[i], r_ev_max[i]);
    }
    
    long long ans = -inf;
    for (int i = 1; i < n; i++) {
      ans = max(ans, r_max[i + 1] - l_min[i]);
      ans = max(ans, l_max[i] - r_min[i + 1]);
    }
    printf("%I64d\n", ans);
  }
  return 0;
}

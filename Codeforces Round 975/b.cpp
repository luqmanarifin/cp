#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int a[N], l[N], r[N], mn, n;

bool can(int x) {
  int nowl = x, nowr = x, now = 1;
  for (int cur_time = mn; cur_time <= n; cur_time++) {
    int add_lef = (l[cur_time] < nowl? nowl - l[cur_time] : 0);
    int add_rig = (r[cur_time] > nowr? r[cur_time] - nowr : 0);
    now += add_lef + add_rig;
    if (now > cur_time) return 0;
    nowl = min(nowl, l[cur_time]);
    nowr = max(nowr, r[cur_time]);
  }
  return 1;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);

    for (int i = 0; i <= n; i++) {
      l[i] = N;
      r[i] = 0;
    }

    mn = N;
    for (int i = 1; i <= n; i++) {
      scanf("%d", a + i);
      mn = min(mn, a[i]);
      l[a[i]] = min(l[a[i]], i);
      r[a[i]] = max(r[a[i]], i);
    }
    for (int x = mn; x <= n; x++) {
      l[x] = min(l[x], l[x - 1]);
      r[x] = max(r[x], r[x - 1]);
    }
    if (!can(l[mn])) {
      puts("0");
      continue;
    }
    int good_lef = l[mn], good_rig = l[mn];
    {
      int lef = 1, rig = good_lef;
      while (lef < rig) {
        int mid = (lef + rig) >> 1;
        if (can(mid)) {
          rig = mid;
        } else {
          lef = mid + 1;
        }
      }
      good_lef = lef;
    }
    {
      int lef = good_rig, rig = n;
      while (lef < rig) {
        int mid = (lef + rig + 1) >> 1;
        if (can(mid)) {
          lef = mid;
        } else {
          rig = mid - 1;
        }
      }
      good_rig = lef;
    }
    printf("%d\n", good_rig - good_lef + 1);
  }

  return 0;
}

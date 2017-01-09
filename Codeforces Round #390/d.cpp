#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;

int lef[N], rig[N];

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  vector<pair<int, int>> all;
  for (int i = 0; i < n; i++) {
    scanf("%d %d", lef + i, rig + i);
    all.emplace_back(lef[i], rig[i]);
  }
  sort(all.begin(), all.end());
  
  int ans = 0, pl = -1, pr = -1;
  multiset<int> til;
  for (int i = 0; i < all.size(); i++) {
    til.insert(all[i].second);
    while (i + 1 < all.size() && all[i].first == all[i + 1].first) {
      til.insert(all[++i].second);
    }
    while (!til.empty() && *(til.begin()) < all[i].first) {
      til.erase(til.begin());
    }
    while (til.size() > k) {
      til.erase(til.begin());
    }
    if (til.size() == k) {
      int cur = *(til.begin()) - all[i].first + 1;
      if (cur > ans) {
        ans = cur;
        pl = all[i].first;
        pr = *(til.begin());
      }
    }
  }
  //printf("%d %d %d\n", ans, pl, pr);
  if (ans == 0) {
    puts("0");
    for (int i = 1; i <= k; i++) printf("%d ", i);
  } else {
    printf("%d\n", ans);
    int now = 0;
    for (int i = 0; i < n; i++) {
      //printf("anjing %d %d %d\n", now, lef[i], rig[i]);
      if (now < k && lef[i] <= pl && pr <= rig[i]) {
        printf("%d ", i + 1);
        now++;
      }
    }
  }
  return 0;
}

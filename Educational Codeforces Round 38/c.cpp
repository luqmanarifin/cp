
#include <bits/stdc++.h>

using namespace std;

const int N = 37000;

vector<tuple<long long, int, int>> mp;

int main() {
  for (int i = 1; i < N; i++) {
    for (int j = 1; j <= i; j++) {
      int l = j, r = i;
      while (l < r) {
        int mid = (l + r + 1) >> 1;
        if (i / j <= i / mid) {
          l = mid;
        } else {
          r = mid - 1;
        }
      }
      long long ans = 1LL * i * i - 1LL * (i / l) * (i / l);
      if (ans <= 1e9) {
        mp.emplace_back(ans, i, j);
      }
      j = l;
    }
    //printf("%d\n", i);
  }
  sort(mp.begin(), mp.end());
  printf("%lld %d %d\n", get<0>(mp.back()), get<1>(mp.back()), get<2>(mp.back()));
  
  /*
  for (int i = 0; i < mp.size(); i++) {
    printf("%d\n", get<0>(mp[i]));
    while (i + 1 < mp.size() && get<0>(mp[i]) == get<0>(mp[i + 1])) i++;
  }
  */
  
  int t;
  scanf("%d", &t);
  while (t--) {
    int x;
    scanf("%d", &x);
    auto it = lower_bound(mp.begin(), mp.end(), make_tuple(x, -1, -1)) - mp.begin();
    if (it < mp.size() && get<0>(mp[it]) == x) {
      printf("%d %d\n", get<1>(mp[x]), get<2>(mp[x]));
    } else {
      puts("-1");
    }
  }
  return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, d, h;
  scanf("%d %d %d", &n, &d, &h);
  if(!(h <= d && d <= 2 * h) || n < d + 1) {
    puts("-1");
    return 0;
  }
  vector<pair<int, int>> ans;
  for(int i = 2; i <= h + 1; i++) {
    ans.emplace_back(i, i - 1);
  }
  int now = h + 1;
  int s = d - h;
  if(s) {
    ans.emplace_back(1, now + 1);
    now++;
    s--;
    for(int i = 1; i <= s; i++) {
      ans.emplace_back(now + i - 1, now + i);
    }
    now = now + s;
    for(int i = now + 1; i <= n; i++) {
      ans.emplace_back(1, i);
    }
  } else {
    int lom = n - now;
    if(lom) {
      if(d == 1) {
        puts("-1");
        return 0;
      }
      for(int i = now + 1; i <= n; i++) {
        ans.emplace_back(2, i);
      }
    }
  }
  for(auto it : ans) printf("%d %d\n", it.first, it.second);
  return 0;
}

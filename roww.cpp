#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;

int a[N];

int main() {
  int n;
  scanf("%d", &n);
  set<int> all;
  for(int i = 1; i <= n; i++) {
    scanf("%d", a + i);
    all.insert(a[i]);
  }
  if(all.size() == n) {
    puts("-1");
    return 0;
  }
  vector<pair<int, int>> ans;
  for(int i = 1; i <= n; ) {
    set<int> s;
    bool good = 0;
    int j = i;
    for(; j <= n; j++) {
      if(s.count(a[j])) {
        good = 1;
        break;
      } else {
        s.insert(a[j]);
      }
    }
    if(good) {
      ans.emplace_back(i, j);
    }
    i = j + 1;
  }
  if(ans.back().second != n) {
    ans.back().second = n;
  }
  printf("%d\n", ans.size());
  for(auto it : ans) {
    printf("%d %d\n", it.first, it.second);
  }
  return 0;
}

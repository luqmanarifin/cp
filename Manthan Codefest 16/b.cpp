#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

int main() {
  int n;
  scanf("%d", &n);
  vector<int> p;
  int now = 0;
  for(int i = 5; now < n; i += 5) {
    int j = i;
    while(j % 5 == 0) {
      now++;
      j /= 5;
    }
    if(now == n) {
      p.push_back(i);
    }
  }
  vector<int> ans;
  for(auto it : p) {
    for(int i = 0; i < 5; i++) {
      ans.push_back(it + i);
    }
  }
  sort(ans.begin(), ans.end());
  printf("%d\n", ans.size());
  for(auto it : ans) printf("%d ", it);
  return 0;
}

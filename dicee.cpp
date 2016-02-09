#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

long long a[N];

int main() {
  int n;
  long long want;
  scanf("%d %I64d", &n, &want);
  long long sum = 0;
  for(int i = 0; i < n; i++) {
    scanf("%I64d", &a[i]);
    sum += a[i];
  }
  for(int i = 0; i < n; i++) {
    vector<pair<int, int>> be;
    if(want - (sum - a[i]) - 1 > 0) {
      be.push_back(make_pair(1, want - (sum - a[i]) - 1));
    }
    if(a[i] + n - 1 > want) {
      be.push_back(make_pair(want - (n - 1) + 1, a[i]));
    }
    int ans = 0;
    if(be.size()) {
      sort(be.begin(), be.end());
      if(be.size() == 2) {
        if(be[0].second >= be[1].first) {
          be[0].second = be[1].first - 1;
        }
      }
    }
    for(auto it : be) {
      ans += it.second - it.first + 1;
    }
    printf("%d ", ans);
  }
  printf("\n");
  return 0;
}

#include <bits/stdc++.h>

using namespace std;

vector<int> ans[105];
pair<int, int> a[105];

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  for(int i = 0; i < n; i++) {
    scanf("%d", &a[i].first);
    a[i].second = i;
  }
  sort(a, a + n);
  if(a[n - 1].first - a[0].first > k) {
    puts("NO");
    return 0;
  }
  puts("YES");
  int req = a[0].first;
  for(int i = 0; i < n; i++) {
    for(int tt = 0; tt < req; tt++) {
      ans[a[i].second].push_back(1);
    }
    for(int j = 1; req + j <= a[i].first; j++) {
      ans[a[i].second].push_back(j);
    }
  }
  for(int i = 0; i < n; i++) {
    for(auto it : ans[i]) {
      printf("%d ", it);
    }
    printf("\n");
  }
  return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main() {
  vector<int> num, ans;
  int p, n;
  scanf("%d %d", &p, &n);
  for(int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    num.push_back(a);
  }
  num.push_back(0);
  num.push_back(p);
  sort(num.begin(), num.end());
  num.resize(distance(num.begin(), unique(num.begin(), num.end())));
  for(int i = 0; i < num.size(); i++) {
    for(int j = i + 1; j < num.size(); j++) {
      ans.push_back(num[j] - num[i]);
    }
  }
  sort(ans.begin(), ans.end());
  ans.resize(distance(ans.begin(), unique(ans.begin(), ans.end())));
  for(int i = 0; i < ans.size(); i++) {
    if(i) printf(" ");
    printf("%d", ans[i]);
  }
  return 0;
}

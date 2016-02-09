#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;

int a[N];
vector<int> num;
vector<pair<int, int>> p;

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  for(int i = 1; i < n - 1; i++) {
    if(a[i] != a[i - 1] & a[i] != a[i + 1]) {
      num.push_back(i);
    }
  }
  int ans = 0;
  for(int i = 0; i < num.size(); ) {
    int j = i + 1;
    while(j < num.size() && num[j - 1] + 1 == num[j]) j++;
    p.emplace_back(num[i], num[j - 1]);
    int cnt = j - i;
    ans = max(ans, cnt / 2 + cnt % 2);
    i = j;
  }
  for(auto it : p) {
    for(int i = 0; it.first + i <= it.second - i; i++) {
      a[it.first + i] = a[it.first + i - 1];
      a[it.second - i] = a[it.second - i + 1];
    }
  }
  printf("%d\n", ans);
  for(int i = 0; i < n; i++) {
    printf("%d ", a[i]);
  }
  return 0;
}

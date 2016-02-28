#include <bits/stdc++.h>

using namespace std;

int main() {
  vector<int> num;
  int n, m;
  scanf("%d %d", &n, &m);
  int now = 0;
  for(int i = 0; i < n; i++) {
    int c, t;
    scanf("%d %d", &c, &t);
    now += c * t;
    num.push_back(now);
  }
  while(m--) {
    int v;
    scanf("%d", &v);
    int id = lower_bound(num.begin(), num.end(), v) - num.begin();
    printf("%d\n", id + 1);
  }
  
  return 0;
}

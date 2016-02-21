#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
const int POL = 1e6 + 5;

int a[N];
vector<int> p[POL];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for(int i = 1; i <= n; i++) {
    scanf("%d", a + i);
    p[a[i]].push_back(i);
  }
  while(m--) {
    int lef, rig, k;
    scanf("%d %d %d", &lef, &rig, &k);
    int low = lower_bound(p[k].begin(), p[k].end(), lef) - p[k].begin();
    int hig = upper_bound(p[k].begin(), p[k].end(), rig) - p[k].begin();
    if(hig - low == rig - lef + 1) {
      puts("-1");
      continue;
    }
    int l = 0, r = rig - lef;
    while(l < r) {
      int mid = (l + r) >> 1;
      if(low + mid < p[k].size() && p[k][low + mid] == lef + mid)  {
        l = mid + 1;
      } else {
        r = mid;
      }
    }
    printf("%d\n", lef + l);
  }
  return 0;
}
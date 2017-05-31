#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int a[N], l[N], r[N], k[N];
map<int, int> ask[N];
int ans[N];

vector<int> all;
int* bit;

int id(int x) {
  return lower_bound(all.begin(), all.end(), x) - all.begin();
}

void update(int i) {
  for (; i >= 0; i = (i & (i + 1)) - 1) bit[i]++;
}

int find(int i) {
  int ret = 0;
  for (; i < all.size(); i |= i + 1) ret += bit[i];
  return ret;
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
    all.push_back(a[i]);
  }
  int q;
  scanf("%d", &q);
  for (int i = 1; i <= q; i++) {
    scanf("%d %d %d", &l[i], &r[i], &k[i]);
    ask[l[i]-1][k[i]] = 0;
    ask[r[i]][k[i]] = 0;
    all.push_back(k[i]);
  }
  sort(all.begin(), all.end());
  all.resize(distance(all.begin(), unique(all.begin(), all.end())));
  bit = new int[all.size()];
  memset(bit, 0, sizeof(bit));
  
  for (int i = 1; i <= n; i++) {
    int di = id(a[i]);
    update(di);
    for (auto it : ask[i]) {
      int at = id(it.first);
      ask[i][it.first] = find(at + 1);
    }
  }
  for (int i = 1; i <= q; i++) {
    printf("%d\n", ask[r[i]][k[i]] - ask[l[i]-1][k[i]]);
  }
  return 0;
}

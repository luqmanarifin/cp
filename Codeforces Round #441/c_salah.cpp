#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

vector<int> a[N];
map<pair<int, int>, bool> mp;

// less
bool cmp(int l, int r) {
  if (mp[{l, r}]) return mp[{l, r}];
  int sz = min(a[l].size(), a[r].size());
  for (int i = 0; i < sz; i++) {
    if (a[l][i] < a[r][i]) {
      return mp[{l, r}] = 1;
    } else if (a[l][i] > a[r][i]) {
      return mp[{l, r}] = 0;
    }
  }
  return mp[{l, r}] = (a[l].size() < a[r].size());
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    int v;
    scanf("%d", &v);
    while (v--) {
      int k;
      scanf("%d", &k);
      a[i].push_back(k);
    }
  }
  vector<int> num(n);
  for (int i = 0; i < n; i++) num[i] = i;
  sort(num.begin(), num.end(), cmp);
  printf("sorted "); for (auto it : num) printf("%d ", it); printf("\n");
  
  int la = -1, lb = -1;
  vector<int> ans;
  for (auto it : num) {
    if (la == -1) {
      la = it;
      continue;
    }
    if (lb == -1) {
      if (cmp(it, la)) {
        lb = it;
        ans.push_back(it);
      } else {
        la = it;
      }
    } else {
      int less_a = cmp(it, la);
      int less_b = cmp(it, lb);
      if (less_a && less_b) {
        puts("No");
        return 0;
      } else {
        if (less_a && !less_b) {
          lb = it;
          ans.push_back(it);
        } else if (!less_a && less_b) {
          la = it;
        } else {
          if (cmp(la, lb)) {
            la = it;
          } else {
            lb = it;
            ans.push_back(it);
          }
        }
      }
    }
  }
  puts("Yes");
  printf("%d\n", ans.size());
  for (auto it : ans) printf("%d ", it + 1);

  return 0;
}

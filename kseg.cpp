// too easy to AC
#include <bits/stdc++.h>

using namespace std;

const int N = 4e6 + 5;

int v[N], l[N], r[N];
vector<int> p;

int id(int a) {
  return lower_bound(p.begin(), p.end(), a) - p.begin();
}

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  for(int i = 0; i < n; i++) {
    scanf("%d %d", l + i, r + i);
    p.push_back(l[i]);
    p.push_back(r[i]);
  }
  sort(p.begin(), p.end());
  p.resize(distance(p.begin(), unique(p.begin(), p.end())));
  for(int i = 0; i < n; i++) {
    int il = id(l[i]);
    int ir = id(r[i]);
    v[2 * il]++;
    v[2 * ir + 1]--;
  }
  for(int i = 1; i < N; i++) {
    v[i] += v[i - 1];
  }
  vector<pair<int, int>> ans;
  for(int i = 0; i < N; i++) {
    int j = i;
    while(j < N && v[j] >= k) j++;
    if(v[i] >= k) {
      ans.emplace_back(p[i / 2], p[j / 2]);
    }
    i = j;
  }
  printf("%d\n", ans.size());
  for(auto it : ans) {
    printf("%d %d\n", it.first, it.second);
  }
  return 0;
}

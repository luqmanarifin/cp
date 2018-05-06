
#include <bits/stdc++.h>

#define int long long

using namespace std;

map<long long, set<int>> pos;
set<long long> kem;
set<pair<int, long long>> a; 

void add(int i, long long v) {
  pos[v].insert(i);
  a.insert(make_pair(i, v));
  if (pos[v].size() == 2) kem.insert(v);
}

void remove(int i) {
  long long v = (a.lower_bound(make_pair(i, -1)))->second;
  pos[v].erase(i);
  a.erase(make_pair(i, v));
  if (pos[v].size() == 1) kem.erase(v);
}

main() {
  int n;
  scanf("%lld", &n);
  for (int i = 1; i <= n; i++) {
    int v;
    scanf("%lld", &v);
    add(i, v);
  }
  while (!kem.empty()) {
    auto smallest = kem.begin();
    long long num = *smallest;
    //printf("hapus %lld\n", num);
    assert(pos[num].size() >= 2);
    auto idx_l = pos[num].begin();
    auto idx_r = idx_l;
    idx_r++;
    int l = *idx_l;
    int r = *idx_r;
    remove(l);
    remove(r);
    add(r, num * 2LL);
  }
  printf("%d\n", a.size());
  for (auto it : a) printf("%lld ", it.second);
  return 0;
}

#include <bits/stdc++.h>

using namespace std;

int n;
int pmin[42], pmax[42];
int win[42][42];
set <long long> mp;

void go(vector <int> &a) {
  long long hash = 0;
  for (int i = 0; i < n; i++) {
    hash = hash * 10 + a[i];
  }
  if (mp.find(hash) != mp.end()) return;
  mp.insert(hash);
  int mn = 42, x = -1;
  for (int i = 0; i < n; i++) {
    if (a[i] < mn && a[i] > 0) {
      mn = a[i];
      x = i;
    }
  }
  bool found = false;
  for (int i = 0; i < n; i++) {
    if (a[i] == mn && i != x) {
      found = true;
      bool flag = false;
      if (!win[i][x]) {
        swap(i, x);
        flag = true;
      }
      pmin[x] = min(pmin[x], a[x]);
      pmax[x] = max(pmax[x], a[x]);
      a[x] = 0;
      a[i]++;
      go(a);
      a[i]--;
      a[x] = a[i];
      if (flag) {
        swap(i, x);
      }
    }
  }
  if (!found) {
    pmin[x] = min(pmin[x], a[x]);
    pmax[x] = max(pmax[x], a[x]);
    return;
  }
}

inline int trans(int n, int rnd) {
  int x = n + 1;
  while (rnd > 0) {
    x = (x + 1) / 2;
    rnd--;
  }
  return x;
}

int main() {
  freopen("in", "r", stdin);
  freopen("out", "w", stdout);
  int tt;
  scanf("%d", &tt);
  for (int qq = 1; qq <= tt; qq++) {
    printf("Case #%d: \n", qq);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        scanf("%d", win[i] + j);
      }
    }
    for (int i = 0; i < n; i++) {
      pmin[i] = 42;
      pmax[i] = -42;
    }
    vector <int> rnd(n);
    for (int i = 0; i < n; i++) {
      rnd[i] = 1;
    }
    mp.clear();
    go(rnd);
    cerr << "case " << qq << ", final mp.size() = " << mp.size() << ", clock() = " << clock() << endl;
    for (int i = 0; i < n; i++) {
      printf("%d %d\n", trans(n, pmax[i]), trans(n, pmin[i]));
    }
  }
  return 0;
}

#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int col[N][3], id[N];

// warna, id
set<pair<int, int>> sval;
int val[N];

map<int, int> mp;

int change(int i, int be) {
  sval.erase({val[i], -id[i]});
  val[i] = be;
  sval.insert({val[i], -id[i]});
}

void remove(int i) {
  sval.erase({val[i], -id[i]});
}

// warna, i
set<pair<int, int>> s[3];
int cnt[400][3];

int add(int i, int j) {
  if (cnt[col[i][j]][j] > 1) return 0;
  int cur = 0;
  auto it = s[j].lower_bound({col[i][j], i});
  it++;
  if (it != s[j].end()) {
    cur += it->first - col[i][j];
  } else {
    auto beg = s[j].begin();
    cur += beg->first + 360 - col[i][j];
  }
  it--;
  if (it != s[j].begin()) {
    it--;
    cur += col[i][j] - it->first;
  } else {
    auto en = s[j].end();
    en--;
    cur += col[i][j] + 360 - en->first;
  }
  return cur;
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 3; j++) {
      scanf("%d", &col[i][j]);
      s[j].insert({col[i][j], i});
      cnt[col[i][j]][j]++;
    }
    scanf("%d", id + i);
    mp[id[i]] = i;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 3; j++) {
      val[i] += add(i, j);
    }
    sval.insert({val[i], -id[i]});
  }
  
  for (int i = 0; i < n; i++) {
    auto it = sval.begin();
    int id = -it->second;
    printf("%d\n", -it->second);
    int at = mp[id];
    sval.erase(it);
    
    if (i == n - 1) break;
    
    set<int> c;
    for (int j = 0; j < 3; j++) {
      auto it = s[j].lower_bound({col[at][j], at});
      it++;
      if (it != s[j].end()) {
        c.insert(it->second);
      } else {
        auto beg = s[j].begin();
        c.insert(beg->second);
      }
      it--; // BALIKIN LAGI
      if (it != s[j].begin()) {
        it--;
        c.insert(it->second);
      } else {
        auto en = s[j].end();
        en--;
        c.insert(en->second);
      }
    }
    for (int j = 0; j < 3; j++) {
      cnt[col[at][j]][j]--;
      s[j].erase({col[at][j], at});
    }
    for (auto it : c) {
      int cur = 0;
      for (int j = 0; j < 3; j++) cur += add(it, j);
      remove(it);
      change(it, cur);
    }
  }

  return 0;
}

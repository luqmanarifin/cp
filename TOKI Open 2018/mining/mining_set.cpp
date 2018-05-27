#include "mining.h"
#include <bits/stdc++.h>

using namespace std;

const int N = 1005;
const int n = 1000;
const int lim = 1000;

bool is[2 * N * N];
int nope[N][N];
set<pair<int, int>> s;

int ada = n * n;

void remove(int x, int y) {
  if (nope[x][y]) return;
  ada--;
  nope[x][y] = 1;
  s.erase(make_pair(x, y));
}

bool valid(int i, int j) {
  return 1 <= i && i <= n && 1 <= j && j <= n;
}

void findGold() {
  for (int i = 0; i * i < 2 * N * N; i++) {
    is[i * i] = 1;
  }  
  
  vector<pair<int, int>> ps;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (is[i * i + j * j]) {
        ps.emplace_back(i, j);
      }
      s.insert(make_pair(i + 1, j + 1));
    }
  }
  srand(time(0));
  random_shuffle(ps.begin(), ps.end());
  vector<int> d = {1, -1};
  while (ada > lim) {
    //printf("ada %d\n", ada);
    int x = rand() % n + 1;
    int y = rand() % n + 1;
    while (nope[x][y]) {
      x = rand() % n + 1;
      y = rand() % n + 1;
    }
    bool ret = isIntegerDistance(x, y);
    if (!ret) {
      for (auto dx : d) {
        for (auto dy : d) {
          for (auto it : ps) {
            int tx = x + dx * it.first;
            int ty = y + dy * it.second;
            if (!valid(tx, ty)) continue;
            remove(tx, ty);
          }
        }
      }
    } else {
      set<pair<int, int>> nx;
      for (auto dx : d) {
        for (auto dy : d) {
          for (auto it : ps) {
            int tx = x + dx * it.first;
            int ty = y + dy * it.second;
            if (!valid(tx, ty)) continue;
            if (!nope[tx][ty]) {
              nx.insert(make_pair(tx, ty));
            }
          }
        }
      }
      auto temp = s;
      //puts("wow mulai gg");
      for (auto it : temp) {
        if (!nx.count(it)) {
          remove(it.first, it.second);
        }
      }
    }
  }
  do {
    //printf("phase 2 %d\n", ada);
    int x = -1, y = -1, be = 1e9;
    auto awal = s.begin();
    set<pair<int, int>> temp = s;
    int udah = 0;
    for (auto dx : d) {
      for (auto dy : d) {
        for (auto it : ps) {
          int tx = awal->first + dx * it.first;
          int ty = awal->second + dy * it.second;
          if (!valid(tx, ty)) continue;
          temp.insert(make_pair(tx, ty));
        }
      }
    }
    hell:;
    for (auto it : temp) {
      int bulat = 0, tidak = 0;
      for (auto j : s) {
        int dx = it.first - j.first;
        int dy = it.second - j.second;
        if (is[dx * dx + dy * dy]) {
          bulat++;
        } else {
          tidak++;
        }
      }
      int cur = max(bulat, tidak);
      if (cur < be) {
        be = cur;
        x = it.first;
        y = it.second;
      }
    }
    bool ret = isIntegerDistance(x, y);
    temp = s;
    if (!ret) {
      for (auto it : temp) {
        int dx = x - it.first;
        int dy = y - it.second;
        if (is[dx * dx + dy * dy]) {
          remove(it.first, it.second);
        }
      }
    } else {
      for (auto it : temp) {
        int dx = x - it.first;
        int dy = y - it.second;
        if (!is[dx * dx + dy * dy]) {
          remove(it.first, it.second);
        }
      }
    }
  } while (s.size() > 1);
  auto ans = s.begin();
  answer(ans->first, ans->second);
}

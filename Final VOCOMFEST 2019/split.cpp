#include <bits/stdc++.h>

using namespace std;

const int N = 8005;

map<int, map<int, int>> cnt;
map<int, int> lef;

map<int, map<int, int>> all;
vector<tuple<int, int, int>> st;

int factor, side, side_now;

bool can() {
  vector<int> factors = {factor};
  bool perfect = 0;
  for (auto j : factors) {
    bool bad = 0;
    for (auto it : lef) {
      if (it.second % j) {
        bad = 1;
        break;
      }
    }
    if (bad) continue;
    vector<pair<int, int> > base;
    // printf("factor %d\n", j);
    for (auto it : cnt) {
      int copies = lef[it.first] / j;
      if (copies == 0) continue;
      bool good = 1;
      vector<pair<int, int> > cur;
      for (auto jt : it.second) {
        if (jt.second % copies) {
          good = 0;
          break;
        }
        if (jt.second == 0) continue;
        cur.emplace_back(jt.first, jt.second / copies);
      }
      if (!good) {
        bad = 1;
        break;
      }
      sort(cur.begin(), cur.end());
      if (base.empty()) {
        base = cur;
      } else {
        if (base != cur) {
          bad = 1;
          break;
        }
      }
    }
    if (bad) continue;
    perfect = 1;
    break;
  }
  // printf("perfect %d\n\n", perfect);
  return perfect;
}

void insert(int x, int y) {
  if (lef[x] % factor == 0) side_now += x;
  lef[x]++;
  cnt[x][y]++;
}

void erase(int x, int y) {
  lef[x]--;
  cnt[x][y]--;
  if (lef[x] % factor == 0) side_now -= x;
}

bool dfs(int at) {
  if (side_now > side) return 0;
  if (at == st.size()) return can();
  int count, x, y;
  tie(count, x, y) = st[at];
  for (int i = 0; i < count; i++) {
    insert(x, y);
  }
  for (int swapped = 0; swapped <= count; swapped++) {
    if (dfs(at + 1)) return 1;
    if (swapped < count) {
      erase(x, y);
      insert(y, x);
    }
  }
  for (int i = 0; i < count; i++) {
    erase(y, x);
  }
  return 0;
}

map<int, int> sq;

bool solve() {
  long long sum = 0;
  for (auto it : st) {
    int x, y, z;
    tie(x, y, z) = it;
    sum += 1LL * x * y * z;
  }
  if (!sq.count(sum)) return 0;
  side = sq[sum];
  vector<int> factors = {1, 2, 3, 4};
  for (auto it : factors) {
    factor = it;
    side_now = 0;
    if (dfs(0)) return 1;
  } 
  return 0;
}

int main() {
  for (int i = 1; i * i < 16e8; i++) {
    sq[i * i] = i;
  }

  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    cnt.clear();
    lef.clear();
    all.clear();
    st.clear();

    for (int i = 0; i < 24; i++) {
      int x, y;
      scanf("%d %d", &x, &y);
      if (x > y) swap(x, y);
      all[x][y]++;
    }
    for (auto it : all) {
      for (auto jt : it.second) {
        st.emplace_back(jt.second, it.first, jt.first);
      }
    }
    sort(st.begin(), st.end());
    reverse(st.begin(), st.end());
    printf("Case #%d: %s\n", tt, solve()? "RUN!" : "STAY");
  }

  return 0;
}

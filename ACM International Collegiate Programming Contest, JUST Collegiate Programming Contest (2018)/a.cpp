#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstdio>
#include <climits>
#include <vector>
#include <map>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <sstream>
#include <string>
#include <cstring>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <utility>
#include <functional>
#include <cassert>

using namespace std;

const int N = 1e5 + 5;

int a[N];
set<int> s;
map<int, int> m;

void add(int v) {
  m[v]++;
  if (m[v] == 1) {
    s.insert(v);
  }
}

void rem(int v) {
  m[v]--;
  if (m[v] == 0) {
    s.erase(v);
  }
}

int solve() {
  return s.size() - s.count(0);
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    s.clear();
    m.clear();

    int n, q;
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++) {
      scanf("%d", a + i);
      add(a[i]);
    }
    while (q--) {
      int tc;
      scanf("%d", &tc);
      if (tc == 1) {
        int p, v;
        scanf("%d %d", &p, &v);
        rem(a[p]);
        a[p] = v;
        add(a[p]);
      } else {
        printf("%d\n", solve());
      }
    }
  }

  return 0;
}

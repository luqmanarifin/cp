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

set<pair<int, int> > s[4];

pair<int, int> insert(pair<int, int> x, int i) {
  if (i == 0) {
    return make_pair(x.first, x.second);
  } else if (i == 1) {
    return make_pair(x.first, -x.second);
  } else if (i == 2) {
    return make_pair(-x.first, x.second);
  } else {
    return make_pair(-x.first, -x.second);
  }
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    for (int j = 0; j < 4; j++) {
      s[j].insert(insert(make_pair(x, y), j));
    }
  }
  while (!s[0].empty()) {
    // pairing two point di sini dari 4 sudut, pilih yg bikin luas terbesar
  }
  // validasi rectangle di sini. males banget anjing argh

  return 0;
}

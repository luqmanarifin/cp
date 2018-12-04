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

int get_hour(int h, int m) {
  return h * 60 + m;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m;
    scanf("%d %d", &n, &m);
    int tot = 0;
    for (int i = 0; i < n; i++) {
      int a, b, c, d;
      scanf("%d:%d %d:%d", &a, &b, &c, &d);
      int be = get_hour(a, b);
      int en = get_hour(c, d);
      tot += en - be;
    }
    m = get_hour(m, 0);
    if (tot >= m) {
      puts("YES");
    } else {
      puts("NO");
    }
  }

  return 0;
}

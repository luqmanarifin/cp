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

int main() {
  int n, m, a, b, x, y;
  scanf("%d %d %d %d %d %d", &n, &m, &a, &b, &x, &y);
  int dx = x - a;
  int dy = abs(y - b);
  if (dx <= 0) {
    puts("TIDAK");
    return 0;
  }
  if (dy > dx) {
    puts("TIDAK");
    return 0;
  }
  if (dx % 2 != dy % 2) {
    puts("TIDAK");
    return 0;
  }
  puts("YA");
  return 0;
}

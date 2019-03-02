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

const int inf = 2e9;

int main() {
  int mini = inf, maxi = -inf;
  long long sum = 0;
  int n;
  scanf("%d", &n);
  while (n--) {
    int a;
    scanf("%d", &a);
    mini = min(mini, a);
    maxi = max(maxi, a);
    sum += a;
  }
  printf("%d %d %lld\n", mini, maxi, sum);
  return 0;
}

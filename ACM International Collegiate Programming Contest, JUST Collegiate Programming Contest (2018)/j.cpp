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

const int N = 1e4 + 5;

int cnt[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    memset(cnt, 0, sizeof(cnt));
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      int v;
      scanf("%d", &v);
      cnt[v]++;
    }
    int ans = 0;
    for (int i = 0; i <= 10000; i++) {
      ans = max(ans, cnt[i] + cnt[i + 1]);
    }
    printf("%d\n", ans);
  }

  return 0;
}

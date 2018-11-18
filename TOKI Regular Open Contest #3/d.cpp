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

const int N = 1005;

int a[N][N];

int ask(int i, int j) {
  printf("? %d %d\n", i, j);
  fflush(stdout);
  int ans;
  scanf("%d", &ans);
  return ans;
}

void answer(long long x) {
  printf("! %lld\n", x);
  fflush(stdout);
  exit(0);
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) a[i][1] = ask(i, 1);
  for (int i = 1; i <= m; i++) a[1][i] = ask(1, i);
  for (int i = 2; i <= n; i++) {
    for (int j = 2; j <= m; j++) {
      a[i][j] = (a[i-1][j] ^ a[i][j-1] ^ a[i-1][j-1]);
    }
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      ans += a[i][j];
    }
  }
  answer(ans);
  return 0;
}

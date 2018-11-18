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

int a[N], cnt[N];
vector<int> p[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
    cnt[a[i]]++;
  }
  for (int i = 1; i <= n; i++) {
    p[i % m].push_back(i);
  }
  for (int i = 0; i < m; i++) {
    if (cnt[i] != p[i].size()) {
      puts("-1");
      return 0;
    }
  }
  for (int i = 0; i < n; i++) {
    if (i) printf(" ");
    printf("%d", p[a[i]].back());
    p[a[i]].pop_back();
  }
  printf("\n");
  return 0;
}

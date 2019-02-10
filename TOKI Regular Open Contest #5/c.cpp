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

long long s[N];
int a[N], p[N];

int main() {
  int n;
  long long k;
  scanf("%d %lld", &n, &k);
  for (int i = 1; i <= n; i++) scanf("%d", p + i), a[p[i]] = i;
  for (int i = 2; i <= n; i++) {
    int l = min(a[i - 1], a[i]);
    int r = max(a[i - 1], a[i]);
    s[l]++;
    s[r]--;
    // printf("%d %d\n", a[i-1], a[i]);
  }
  vector<long long> num;
  for (int i = 2; i <= n; i++) {
    s[i] += s[i - 1];
  }
  for (int i = 1; i <= n; i++) {
    num.push_back(s[i]);
    // printf(" %lld\n", s[i]);
  }
  sort(num.begin(), num.end());
  reverse(num.begin(), num.end());
  long long now = 0;
  int ans = 0;
  for (int i = 0; i < num.size(); i++) {
    now += num[i];
    ans++;
    if (now >= k) {
      cout << ans << endl;
      return 0;
    }
  }
  puts("-1");
  return 0;
}

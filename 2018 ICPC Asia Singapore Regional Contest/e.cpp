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

int dp[N][N];
vector<pair<int, int>> to[N];     // to - value
char s[N];
int cnt[30];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    for (int i = 0; i < N; i++) to[i].clear();
    int k;
    scanf("%s %d", s, &k);
    int n = strlen(s);
    for (int i = 0; i < n; i++) {
      memset(cnt, 0, sizeof(cnt));
      for (int j = i; j < n; j++) {
        cnt[s[j] - 'a']++;
      }
    }

  }

  return 0;
}

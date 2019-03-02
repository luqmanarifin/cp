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

int cnt[N];
int ans[N][N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n * n; i++) {
    int a;
    scanf("%d", &a);
    cnt[a]++;
  }
  if (n % 2) {
    int now = 0;
    for (int i = 0; i < n / 2; i++) {
      for (int j = 0; j < n / 2; j++) {
        while (cnt[now] < 4 && now < N) now++;
        if (now == N) break;
        ans[i][j] = now;
        ans[n-1-i][j] = now;
        ans[i][n-1-j] = now;
        ans[n-1-i][n-1-j] = now;
        cnt[now] -= 4;
      }
    }
    now = 0;
    for (int i = 0; i < n / 2; i++) {
      while (cnt[now] < 2 && now < N) now++;
      if (now == N) break;
      ans[i][n/2] = now;
      ans[n-1-i][n/2] = now;
      cnt[now] -= 2;
    }
    now = 0;
    for (int j = 0; j < n / 2; j++) {
      while (cnt[now] < 2 && now < N) now++;
      if (now == N) break;
      ans[n/2][j] = now;
      ans[n/2][n-1-j] = now;
      cnt[now] -= 2;
    }
    now = 0;
    while (cnt[now] < 1 && now < N) now++;
    if (cnt[now] >= 1) {
      ans[n/2][n/2] = now;
      cnt[now]--;
    }
  } else {
    int now = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (ans[i][j]) continue;
        while (cnt[now] < 4 && now < N) now++;
        if (now == N) break;
        ans[i][j] = now;
        ans[n-1-i][j] = now;
        ans[i][n-1-j] = now;
        ans[n-1-i][n-1-j] = now;
        cnt[now] -= 4;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (ans[i][j] == 0) {
        puts("NO");
        return 0;
      }
    }
  }
  puts("YES");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("%d ", ans[i][j]);
    }
    printf("\n");
  }

  return 0;
}

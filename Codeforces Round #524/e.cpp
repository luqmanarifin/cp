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

const int N = 255;

char s[N][N];
int good[N][N][N];
int cnt[26];

long long solve(vector<int>& a) {
  long long ans = 0;
  for (int i = 0; i < a.size(); i++) {
    int j = i;
    while (j + 1 < a.size() && a[j + 1] == a[j] + 1) {
      j++;
    }
    long long len = j - i + 1;
    ans += len * (len + 1) / 2;
    i = j;
  }
  return ans;
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%s", s[i]);
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      memset(cnt, 0, sizeof(cnt));
      int ada = 0;
      for (int k = j; k < m; k++) {
        int c = s[i][k]-'a';
        cnt[c]++;
        if (cnt[c] % 2) {
          ada++;
        } else {
          ada--;
        }
        if (ada <= 1) {
          good[i][j][k] = 1;
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      for (int k = j; k < m; k++) {
        printf("%d %d %d: %d\n", i, j, k, good[i][j][k]);
      }
    }
  }
  long long ans = 0;
  for (int j = 0; j < m; j++) {
    for (int k = j; k < m; k++) {
      vector<int> row;
      printf("%d %d: ", j, k);
      for (int i = 0; i < n; i++) {
        if (good[i][j][k]) {
          row.push_back(i);
        }
      }
      for (auto it : row) printf("%d ", it); printf("\n");
      ans += solve(row);
    }
  }
  cout << ans << endl;
  return 0;
}

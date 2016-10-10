#include <bits/stdc++.h>

using namespace std;

const int N = 2005;
const int inf = 1e9;

// milik - 0 minimum / 1 maksimum - akhir di mana
int lef[N][2][N];
int rig[N][2][N];
int a[N], n;

void update_lef(int i, int j, int k, int val) {
  int* bit = lef[i][j];
  for (; k <= n; k |= k + 1) {
    if (j == 0) {
      bit[k] = min(bit[k], val);
    } else {
      bit[k] = max(bit[k], val);
    }
  }
}

int find_lef(int i, int j, int k) {
  int ret = (j? 0 : inf);
  int* bit = lef[i][j];
  for (; k >= 0; k = (k & (k + 1)) - 1) {
    if (j == 0) {
      ret = min(ret, bit[k]);
    } else {
      ret = max(ret, bit[k]);
    }
  }
  return ret;
}

void update_rig(int i, int j, int k, int val) {
  int* bit = rig[i][j];
  for (; k >= 0; k = (k & (k + 1)) - 1) {
    if (j == 0) {
      bit[k] = min(bit[k], val);
    } else {
      bit[k] = max(bit[k], val);
    }    
  }
}

int find_rig(int i, int j, int k) {
  int ret = (j? 0 : inf);
  int* bit = rig[i][j];
  for (; k <= n; k |= k + 1) {
    if (j == 0) {
      ret = min(ret, bit[k]);
    } else {
      ret = max(ret, bit[k]);
    }
  }
  return ret;
}  

int main() {
  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    scanf("%d", &n);
    
    for (int i = 1; i <= n; i++) {
      fill(lef[i][0], lef[i][0] + n + 1, inf);
      fill(lef[i][1], lef[i][1] + n + 1, 0);
      fill(rig[i][0], rig[i][0] + n + 1, inf);
      fill(rig[i][1], rig[i][1] + n + 1, 0);
    }
    
    for (int i = 1; i <= n; i++) {
      scanf("%d", a + i);
      update_lef(i, 0, i, a[i]);
      update_lef(i, 1, i, a[i]);
      update_rig(i, 0, i, a[i]);
      update_rig(i, 1, i, a[i]);
    }
    vector<tuple<int, int, int, int>> tup;
    for (int len = 2; len <= n; len++) {
      for (int i = 1; i + len - 1 <= n; i++) {
        int j = i + len - 1;
        int mini = min(find_lef(i, 1, j - 1), find_rig(j, 1, i + 1));
        int maks = max(find_lef(i, 0, j - 1), find_rig(j, 0, i + 1));
        update_lef(i, 0, j, mini);
        update_lef(i, 1, j, maks);
        update_rig(j, 0, i, mini);
        update_rig(j, 1, i, maks);
        tup.emplace_back(j, 1, i, max(find_lef(i, 1, j), find_rig(j, 1, i)));
        tup.emplace_back(i, 0, j, min(find_lef(i, 0, j), find_rig(j, 0, i)));
        
        //printf("maks %d %d: %d\n", i, j, max(find_lef(i, 1, j), find_rig(j, 1, i)));
        //printf("mini %d %d: %d\n", i, j, min(find_lef(i, 0, j), find_rig(j, 0, i)));
      }
    }
    sort(tup.begin(), tup.end());
    for (auto it : tup) {
      int b, c, d, e;
      tie(b, c, d, e) = it;
      printf("%d %d %d %d\n", b, c, d, e);
    }
    printf("Case #%d: %d\n", tt, find_lef(1, 0, n));
  }
  
  return 0;
}
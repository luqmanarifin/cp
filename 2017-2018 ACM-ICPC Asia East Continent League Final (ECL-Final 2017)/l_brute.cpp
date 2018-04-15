#include <bits/stdc++.h>

using namespace std;

const int N = 4e8;

short dp[N];
int a[30], n;

int encode() {
  int ret = 0;
  for (int i = n - 1; i >= 0; i--) {
    ret = ret * 3 + a[i];
  }
  return ret;
}

void decode(int mask) {
  for (int i = 0; i < n; i++) {
    a[i] = mask % 3;
    mask /= 3;
  }
}

bool win() {
  for (int i = 0; i + 2 < n; i++) {
    if (a[i] == 1 && a[i + 1] == 2 && a[i + 2] == 1) return 1;
  }
  return 0;
}

int dfs(int mask) {
  //cout << dp[mask] << endl;
  if (dp[mask] != -1) return dp[mask];
  if (win()) return 0;
  bool ada_seri = 0, ada = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] == 0) {
      ada = 1;
      for (int j = 1; j <= 2; j++) {
        a[i] = j;
        int cur = encode();
        if (dfs(cur) == 0) {
          a[i] = 0;
          //~ for (int i = 0; i < n; i++) printf("%d ", a[i]); printf(": ");
          //~ puts("menang");
          return dp[mask] = 2;
        }
        else if (dfs(cur) == 1) {
          ada_seri = 1;
        }
      }
      a[i] = 0;
    }
  }
  //~ for (int i = 0; i < n; i++) printf("%d ", a[i]); printf(": ");
  if (!ada_seri && ada) {
    //~ puts("kalah");
    return dp[mask] = 0;
  } else {
    //~ puts("seri");
    return dp[mask] = 1;
  }
}

int main() {
  for (n = 1; n <= 18; n++) {
    memset(dp, -1, sizeof(dp));
    memset(a, 0, sizeof(a));
    int ret = dfs(0);
    printf("%d: ", n);
    if (ret == 0) {
      puts("Sheep");
    } else if (ret == 1) {
      puts("Draw");
    } else {
      puts("Panda");
    }
  }

  return 0;
}

#include <bits/stdc++.h>

using namespace std;

const int N = 3050;
const int inf = 1e9;

char s[N];
int dp[N], n, sum[N], b[N];

int find(int l, int r) {
  assert(l <= r);
  return sum[r] - sum[l - 1];
}

void backtrack(int i) {
  if(i == 0) return;
  if(b[i] >= 2) {
    backtrack(i - 2*b[i]);
    printf("J %d\n", b[i]);
    int st = i - 2*b[i];
    //printf("%d %d\n", st + b[i] + 1, min(st + 2*b[i] - 1, n + 1));
    for(int t = st + b[i] + 1; t <= min(i, n + 1); t++) {
      printf("W\n");
    }
  } else {
    backtrack(i - 1);
    printf("W\n");
  }
}

bool can(int t, bool ok = 0) {
  for(int i = 1; i < N; i++) {
    dp[i] = -inf;
  }
  dp[0] = t;
  for(int i = 0; i <= n; i++) {
    if(dp[i] <= 0) continue;
    int near = find(i + 1, i + 1);
    if(dp[i + 1] < dp[i] + near) {
      dp[i + 1] = dp[i] + near;
      b[i + 1] = 1;
    } 
    for(int j = 2; j <= dp[i] && i + j <= n + 1; j++) {
      int add = find(i + 1, i + 2 * j) - find(i + 1, i + j - 1);
      if(dp[i] <= j + 1 && find(i + j, i + j + dp[i] - 1) == -dp[i]) continue;
      if(dp[i + 2*j] < dp[i] + add) {
        dp[i + 2*j] = dp[i] + add;
        b[i + 2*j] = j;
      }
    }
  }
  for(int i = n + 1; i < N; i++) {
    if(dp[i] > 0) {
      if(ok) backtrack(i);
      return 1;
    }
  }
  return 0;
}

int main() {
  scanf("%d %s", &n, s + 1);
  for(int i = 1; i < N; i++) {
    sum[i] = sum[i - 1];
    if(s[i] == '+') {
      sum[i]++;
    } else if(s[i] == '-') {
      sum[i]--;
    }
  }
  int l = 1, r = 2 * n;
  while(l < r) {
    int mid = (l + r) >> 1;
    if(can(mid)) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  printf("%d\n", l);
  assert(can(l, 1));
  return 0;
}
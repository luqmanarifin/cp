#include <bits/stdc++.h>

using namespace std;

const int offset = 15000;

int n;
unsigned long long dp[offset * 2], temp[offset * 2];
unsigned long long a[5005];
int num[2005];

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d", num + i);
  }
  for(int i = 0; i < n; i++) {
    for(int j = i + 1; j < n; j++) {
      a[abs(num[i] - num[j])]++;
    }
  }
  dp[offset] = 1;
  for(int it = 0; it < 2; it++) {
    memset(temp, 0, sizeof(temp));
    for(int i = 0; i <= offset; i++) {
      if(dp[i] == 0) continue;
      for(int j = 1; j < 5000; j++) {
        temp[i - j] += dp[i] * a[j];
      }
    }
    for(int i = 0; i < offset * 2; i++) {
      dp[i] = temp[i];
    }
  }
  for(int it = 0; it < 1; it++) {
    memset(temp, 0, sizeof(temp));
    for(int i = 0; i <= offset; i++) {
      if(dp[i] == 0) continue;
      for(int j = 1; j < 5000; j++) {
        temp[i + j] += dp[i] * a[j];
      }
    }
    for(int i = 0; i < offset * 2; i++) {
      dp[i] = temp[i];
    }
  }
  unsigned long long cnt = 0;
  for(int i = offset + 1; i < 2 * offset; i++) cnt += dp[i];
  double ans = cnt;
  for(int i = 0; i < 3; i++) ans /= n * (n - 1) / 2;
  printf("%.15f\n", ans);
  return 0;
}
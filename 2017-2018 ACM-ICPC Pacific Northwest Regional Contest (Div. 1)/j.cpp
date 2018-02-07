#include <bits/stdc++.h>
using namespace std;
const int N = 30;
typedef long long LL;
LL dp[N + 5][N + 5];
char ar[N + 5][N + 5];
int n, m;
int maxB[N + 5];
int minR[N + 5];

inline LL rek(int pos, int minB){
  //fprintf(stderr, "%d %d\n", pos, minB);
  if(pos == 0) return 1;
  if(dp[pos][minB] != -1) return dp[pos][minB];
  LL &ret = dp[pos][minB] = 0;
  int minBleft = maxB[pos - 1];
  for(int i = minB; i < minR[pos]; ++i){
    ret += rek(pos - 1, max(minBleft, i));
  }
  //fprintf(stderr, "dp[%d][%d] : %d\n", pos, minB, dp[pos][minB]);
  return ret;
}

int main(){
  scanf("%d%d", &n, &m);
  for(int i = 0;i < n; ++i){
    scanf("%s", ar[i]);
  }
  for(int i = 0;i < m; ++i){
    minR[i + 1] = n + 1;
    maxB[i + 1] = 0;
    for(int j = 0;j < n; ++j){
      if(ar[j][i] == 'R') minR[i + 1] = min(minR[i + 1], j + 1);
      else if(ar[j][i] == 'B') maxB[i + 1] = max(maxB[i + 1], j + 1);
    }
  }
  memset(dp, -1LL, sizeof dp);
  printf("%lld\n", rek(m, maxB[m]));
  
  return 0;
}
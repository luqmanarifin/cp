#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 200;
int ar[N + 5][N + 5];
int pref[N + 5][N + 5];
int n, m;

bool coba(int x){
  pref[1][1] = x;
  for(int i = 2;i <= m; ++i){
    if(pref[1][i-1] == -1 || pref[1][i-1] + ar[1][i] <= 0) pref[1][i] = -1;
    else pref[1][i] = pref[1][i-1] + ar[1][i];
  }
  for(int i = 2;i <= n; ++i){
    for(int j = 1; j <= m; ++j){
      bool bisa = false;
      pref[i][j] = -1;
      if(pref[i][j-1] > 0 && pref[i][j-1] + ar[i][j] > 0) pref[i][j] = max(pref[i][j], pref[i][j - 1] + ar[i][j]); 
      if(pref[i -1][j] > 0 && pref[i - 1][j] + ar[i][j] > 0) pref[i][j] = max(pref[i][j], pref[i - 1][j] + ar[i][j]); 
    }
  }
  return pref[n][m] != -1;
}
int main(){
  scanf("%d%d", &n, &m);
  for(int i = 1;i <= n; ++i){
    for(int j = 1;j <= m; ++j){
      scanf("%d", &ar[i][j]);
    }
  }
  int lo = 1, hi = 398001;
  int ans = 398001; 
  while(lo <= hi){
    int piv = (lo + hi) >> 1;
    if(coba(piv)){
      ans = piv;
      hi = piv - 1;
    }
    else{
      lo = piv + 1;
    }
  }
  printf("%d\n", ans);
  return 0;
}
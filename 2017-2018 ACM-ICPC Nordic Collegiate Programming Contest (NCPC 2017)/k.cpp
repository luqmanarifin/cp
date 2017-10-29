#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
const int N = 1e5;
const LL INFL = 1e14;
int ar[3];
int s[3];
int c[N + 5];
int n;
int m;


bool coba(LL piv){
  int arr[3] = {ar[0], ar[1], ar[2]};
  for(int i = 0;i < m; ++i){
    bool bisa = false;
    for(int j = 0;j < 3 && !bisa; ++j){
      if(!arr[j]) continue;
      arr[j]--;
      for(int k = j;k < 3 && !bisa; ++k){
        if(arr[k] && (1LL * c[i] * (s[j] + s[k]) >= piv)){
          bisa = true;
          arr[k]--;
        }
      }
      if(!bisa) arr[j]++;
    }
    if(!bisa) return false;
  }
  return true;
}

int main() {
  n = 0;
  for(int i = 0;i < 3; ++i) scanf("%d", &ar[i]), n += ar[i];
  for(int i = 0;i < 3; ++i) scanf("%d", &s[i]);

  m = n >> 1;
  for(int i = 0;i < m; ++i) scanf("%d", &c[i]);
  
  sort(c, c + m);
  
  LL ans = 0;
  LL mini = 0;
  LL maks = INFL;
  while(mini <= maks){
    LL piv = (mini + maks) / 2;
    if(coba(piv)){
      ans = piv;
      mini = piv + 1;
    }
    else{
      maks = piv - 1;
    }
  }
  
  printf("%lld\n", ans);
  return 0;
}

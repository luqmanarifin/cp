#include <bits/stdc++.h>

using namespace std;
const int N = 1e5;
typedef long long LL;
int n, m;

LL ar[N + 5];
LL br[N + 5];
int main() {
  int tc = 0;
  while(scanf("%d%d", &n, &m) != EOF){
    ++tc;
    
    for(int i = 0;i < n; ++i) scanf("%lld", &ar[i]);
    for(int i = 0;i < m; ++i) scanf("%lld", &br[i]);
    sort(ar, ar + n, greater<LL>());
    sort(br, br + m, greater<LL>());
    int st = 0;
    int poia = 1, poib = 1;
    int menang = -1;
    LL nowa = ar[0];
    LL nowb = br[0];
    while(1){
      fprintf(stderr, "KASUS : %d, %d %d %lld %lld\n", st, poia, poib, nowa, nowb);
      if(st == 0){
        if(poia != n && (nowa + ar[poia]) > nowb + (poib != m ? br[poib] : 0)){
          nowa += ar[poia];
          poia++;
        }
        else if(nowa > nowb){
          if(poib == m) {
            menang = 0;
            break;
          }
          nowb = br[poib];
          poib++;
        }
        else{
          if(poia != n){
            nowa += ar[poia];
            poia++;
          }
        }
      }
      else{
        if(poib != m && (nowb + br[poib]) > nowa + (poia != n ? ar[poia] : 0)){
          nowb += br[poib];
          poib++;
        }
        else if(nowb > nowa){

          if(poia == n) {
            menang = 1;
            break;
          }
          nowa = ar[poia];
          poia++;
        }
        else{
          if(poib != m){
            nowb += br[poib];
            poib++;
          }
        }
      }
      
      st ^= 1;
    }
    printf("Case %d: %s\n", tc, (menang) ? "Buyout Limited" : "Takeover Incorporated");
  }
  
  return 0;
}


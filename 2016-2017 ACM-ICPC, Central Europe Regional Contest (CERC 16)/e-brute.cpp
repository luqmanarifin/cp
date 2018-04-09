#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL coba(LL a, LL b, int k){
  LL B = (a + b) * k;
  LL C = a * a + b * b - 1 - a * b * k;
  LL kali = 1LL * B * B - 4LL * C;
  LL akar = (LL) sqrtl(kali);
  if(akar * akar != kali) return -1;
  if((B + akar) & 1) return -1;
  return (B + akar) >> 1;
}

int main(){
  int K, maks;
  scanf("%d%d", &K, &maks);
  for(int i = 1;i <= maks; ++i){
    for(int j = i + 1;j <= maks; ++j){
      LL satulagi = coba(i, j, K);
      if(satulagi != -1){
        printf("%d %d %d\n", i, j, (int) satulagi);
        break;
      }
    }
  }
  return 0;
}

#include <bits/stdc++.h>

using namespace std;

typedef long double LD;
const int N = 10;
LD pol[N + 5];
LD pol2[N * 2 + 5];

int n;

const LD PI = 3.141592653589793238462643383279502884L;

void sqrpol(){
  for(int i = 0;i <= 2 * n; ++i) pol2[i] = 0.0L;
  for(int i = 0;i <= n; ++i){
    for(int j = 0;j <= n; ++j){
      pol2[i + j] += pol[i] * pol[j];
    }
  }
}

void integral(){
  for(int i = 0;i <= 2 * n; ++i){
    pol2[i] /= (i + 1);
  }
}

LD volum(LD x){
  LD ans = 0;
  LD kali = x;
  for(int i = 0;i <= 2 * n; ++i){
    ans += kali * pol2[i];
    kali *= x;
  }
  return ans * PI;
}

int main() {
  int tc = 0;
  while(scanf("%d", &n) != EOF){
    ++tc;
    LD xlow, xhigh;
    int mark;
    for(int i = 0;i <= n; ++i) scanf("%Lf", &pol[i]);
    scanf("%Lf%Lf%d", &xlow, &xhigh, &mark);
    
    sqrpol();
    integral();
    LD volbawah = volum(xlow);
    LD volatas = volum(xhigh);
    LD vol = volatas - volbawah;
    printf("Case %d: %.2Lf\n", tc, vol);
    if(vol < (LD) mark){
      puts("insufficient volume");
      continue;
    }
    int banyak = (int) (vol / (LD) mark);
    banyak = min(banyak, 8);
    LD xbawah = xlow;
    for(int i = 0;i < banyak; ++i){
      LD low = xbawah;
      LD high = xhigh;
      LD ans = xhigh;
      volbawah = volum(xbawah);
      while(high - low >= 0.00001L){
        LD piv = (low + high) / 2.0L;
        LD volpiv = volum(piv) - volbawah;
        if(volpiv > (LD)mark){
          high = piv;
        }
        else{
          low = piv;
          ans = piv;
        }
      }
      printf("%.2Lf%c", ans - xlow, (i == banyak - 1) ? '\n' : ' ');
      xbawah = ans;
    }
  }
  return 0;
}


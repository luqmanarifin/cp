#include <bits/stdc++.h>
using namespace std;
const int N = 20;
char ar[N + 5];

typedef long double LD;
LD h = sqrtl(0.75L);
const LD PI = 3.141592653589793238462643383279502884L;

LD sqr(LD a){
  return a * a;
}

int main(){
  int n;
  scanf("%d", &n);
  scanf("%s", ar);
  LD ans = 0L;
  if(ar[0] == 'T'){
    ans += 1.5L;
  }
  else if(ar[0] == 'C'){
    ans += PI / 2.0L;
  }
  else if(ar[0] == 'S'){
    ans += 2L;
  }
  
  if(ar[n - 1] == 'T'){
    ans += 1.5L;
  }
  else if(ar[n - 1] == 'C'){
    ans += PI / 2.0L;
  }
  else if(ar[n - 1] == 'S'){
    ans += 2L;
  }
  
  ans += n - 1;
  fprintf(stderr, "TOTAL UJUNG : %.10Lf\n", ans);
  
  if(n > 1){
    int bef = 0;
    for(int i = 1; i < n; ++i){
      if(ar[i] == 'C' || ar[i] == 'S'){
        if(ar[bef] == 'C' || ar[bef] == 'S') ans += i - bef;
        else{
          if(ar[i] == 'C'){
            int seli = abs(i - bef);
            LD panjang = sqrtl(sqr(seli) + sqr(h - 0.5L));
            LD sudutbawah = atan2(h - 0.5L, seli);
            LD singgung = sqrtl(sqr(panjang) - 0.25L);
            LD sudutatas = atan2(abs(singgung), 0.5L);
            LD sisasudut = PI / 2.0L - sudutbawah - sudutatas;
            LD busur = sisasudut / 2.0L;
            ans += singgung + busur;
          }
          else {
            ans += 0.5L + sqrtl(sqr(abs(i - bef) - 0.5L) + sqr(1 - h));
          }
        }
        bef = i;
      }
      fprintf(stderr, "TOTAL %d: %.10Lf. Bef : %d\n", i, ans, bef);
    }
    if(bef != n - 1){
      if(ar[bef] == 'T') ans += n - 1 - bef;
      else if(ar[bef] == 'S'){
        ans += 0.5L + sqrtl(sqr(abs((n - 1) - bef) - 0.5L) + sqr(1 - h));
      }
      else{
        int seli = abs(n - 1 - bef);
        LD panjang = sqrtl(sqr(seli) + sqr(h - 0.5L));
        LD sudutbawah = atan2(h - 0.5L, seli);
        LD singgung = sqrtl(sqr(panjang) - 0.25L);
        LD sudutatas = atan2(abs(singgung), 0.5L);
        
        fprintf(stderr, "PANJANG : %.10Lf, SINGGUNG: %.10Lf\n", panjang, singgung); 
        LD sisasudut = PI / 2.0L - sudutbawah - sudutatas;
        fprintf(stderr, "SUDUT BAWAH : %.10Lf, ATAS : %.10Lf, SISA SUDUT : %.10Lf\n", sudutbawah, sudutatas, sisasudut);
        LD busur = sisasudut / 2L;
        ans += singgung + busur;
      }
    }
  }
  
  
  printf("%.10Lf\n", ans);
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int N = 1e6;
int n, k;
int num;
int ar[N + 5];

inline bool coba(int piv){
  int sisa = 0;
  int banyak = 2 * k;
  int cnt = 0;
  for(int i = 0;i < num; ++i){
    sisa++;
    if(sisa >= banyak){
      //fprintf(stderr, "MASUK %d %d\n", i, sisa);
      if(ar[i - 1] - ar[i] > piv) continue;
      else{
        sisa -= banyak;
        if(i < num - 1) sisa++, i++;
        cnt++;
      }
    }
  }
  //fprintf(stderr, "COBA %d %d\n", piv, cnt);
  return cnt == n;
}

int main(){
  scanf("%d%d", &n, &k);
  num = 2 * n * k;
  for(int i = 0;i < num; ++i){
    scanf("%d", &ar[i]);
  }
  sort(ar, ar + num);
  reverse(ar, ar + num);
  int mins = ar[num - 2] - ar[num - 1];
  int maks = ar[0] - ar[num - 1];
  int ans = maks;
  while(mins <= maks){
    int piv = (mins + maks) >> 1;
    if(coba(piv)){
      ans = piv;
      maks = piv - 1;
    }
    else mins = piv + 1;
  }
  printf("%d\n", ans);
  return 0;
}
#include <bits/stdc++.h>
using namespace std;
const int N = 3e5;
int ar[N + 5];
int n, m, a, b;

int main(){
  ios::sync_with_stdio(false);
  cin >> n >> m >> a >> b;
  for(int i = 0; i < n; ++i) cin >> ar[i];
  int CASE = 0;
  int tot_now = m;
  int share = 0;
  int cont = 0;
  for(int i = 1; i < n; ++i){
    if(ar[i] == ar[i - 1]){
      CASE = 0;
      cont = 0;
    }
    else if(ar[i] > ar[i - 1]){
      if(CASE == 1) cont++;
      else CASE = 1, cont = 1;
      int banyak = min(a * cont, tot_now / ar[i]);
      tot_now -= banyak * ar[i];
      share += banyak;
    }
    else {
      if(CASE == -1) cont++;
      else CASE = -1, cont = 1;
      int banyak = min(b * cont, share);
      tot_now += banyak * ar[i];
      share -= banyak;
    }
  }
  printf("%d %d\n", tot_now, share);
  return 0;
}
#include <bits/stdc++.h>

using namespace std;
const int N = 40;

int ar[N + 5], br[N + 5];
int pos[N + 5];
int n;
  
int ask(){
  for(int i = 1;i <= n; ++i) printf("%d%c", br[i], (i == n) ? '\n' : ' ');
  fflush(stdout);

  int res;
  scanf("%d", &res);
  if(res == n) exit(0);
  return res;
}
int main() {
  scanf("%d", &n);
  for(int i = 1; i <= n; ++i) {
    ar[i] = i;
    pos[i] = i;
    br[i] = i;
  }

  int now = ask();
  for(int i = 1;i <= n; ++i){
    //fprintf(stderr, "MASUK %d\n", i);
    bool berhasil = false;
    for(int j = 1;j <= n; ++j) br[j] = ar[j];

    int posnow = pos[i];
    for(int j = posnow - 1;j >= 1 && !berhasil; --j){
      swap(br[j], br[j + 1]);
      int sek = ask();
      if(now < sek) berhasil = true, now = sek;
      else if(now > sek) break;
    }
    if(!berhasil){
      for(int j = 1;j <= n; ++j) br[j] = ar[j];
      for(int j = posnow + 1; j <= n && !berhasil; ++j){
        swap(br[j - 1], br[j]);
        int sek = ask();
        if(now < sek) berhasil = true, now = sek;
        else if(now > sek) break;
      }
    }

    if(berhasil){
      for(int i = 1;i <= n; ++i) ar[i] = br[i],pos[ar[i]] = i;
    }
  }
  assert(false);
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define fi first
#define se second
#define mp make_pair
const int K = 15, N = 1 << K, M = 1 << (2 * K);
int n, m;
vector<int> v;

pii arah[4] = {mp(0, -1), mp(-1, 0), mp(0, 1), mp(1, 0)};


struct matrix{
  int ar[2][2];

  matrix() {}
  matrix(int a, int b, int c, int d) {
    ar[0][0] = a; ar[0][1] = b; ar[1][0] = c; ar[1][1] = d;
  }
} ;

int opposite(int x){
  if(x == 0) return 2;
  else if(x == 2) return 0;
  else if(x == 1) return 3;
  return 1;
}

bool valid(int x, int y){
  return x >= 0 && x < 2 && y >= 0 && y < 2;
}

matrix curmatrix(int prevdir, int nextdir){
  matrix ans;
  if(prevdir == 0){
    if(nextdir == 0) ans = matrix(3, 0, 2, 1);
    else if(nextdir == 1) ans = matrix(3, 0, 2, 1);
    else if(nextdir == 2) ans = matrix(1, 0, 2, 3);
    else if(nextdir == 3) ans = matrix(1, 0, 2, 3);
  }
  else if(prevdir == 1){
    if(nextdir == 0) ans = matrix(3, 2, 0, 1);
    else if(nextdir == 1) ans = matrix(3, 2, 0, 1);
    else if(nextdir == 2) ans = matrix(1, 2, 0, 3);
    else if(nextdir == 3) ans = matrix(1, 2, 0, 3);
  }
  else if(prevdir == 2){
    if(nextdir == 0) ans = matrix(3, 2, 0, 1);
    else if(nextdir == 1) ans = matrix(3, 2, 0, 1);
    else if(nextdir == 2) ans = matrix(1, 2, 0, 3);
    else if(nextdir == 3) ans = matrix(1, 2, 0, 3);
  }
  else{
    if(nextdir == 0) ans = matrix(3, 0, 2, 1);
    else if(nextdir == 1) ans = matrix(3, 0, 2, 1);
    else if(nextdir == 2) ans = matrix(1, 0, 2, 3);
    else if(nextdir == 3) ans = matrix(1, 0, 2, 3);
  }

  return ans;
}

void rek(int idx, int lowr, int lowc, int highr, int highc, int prevdir, int nextdir){
  // printf("DEBUG %d: (%d,%d)-(%d,%d) : %d %d\n", idx, lowr, lowc, highr, highc, prevdir, nextdir); 
  if(idx == (int)v.size()){
    printf("%d %d\n", lowc, lowr);
    return;
  }
  matrix order = curmatrix(prevdir, nextdir);
  int side = (highr - lowr + 1);
  int half = side >> 1;
  int ii = 0;
  int jj = 0;
  for(int i = 0;i < 2; ++i) for(int j = 0;j < 2; ++j) if(v[idx] == order.ar[i][j]){
    ii = i;
    jj = j;
  }
  // printf("II: %d, JJ: %d\n", ii, jj);
  int lowrnext = lowr + (1 - ii) * half;
  int lowcnext = lowc + jj * half;
  int highrnext = highr - ii * half;
  int highcnext = highc - (1 - jj) * half;

  int prevnext = -1, nextnext = -1;
  if(v[idx] == 0) prevnext = prevdir;
  else{
    for(int x = 0; x < 4; ++x){
      int nexti = ii + arah[x].fi;
      int nextj = jj + arah[x].se;
      if(valid(nexti, nextj) && order.ar[nexti][nextj] == v[idx] - 1){
        prevnext = opposite(x);
        break;
      }
    }
  }
  if(v[idx] == 3) nextnext = nextdir;
  else{
    for(int x = 0; x < 4; ++x){
      int nexti = ii + arah[x].fi;
      int nextj = jj + arah[x].se;
      if(valid(nexti, nextj) && order.ar[nexti][nextj] == v[idx] + 1){
        nextnext = x;
        break;
      }
    }
  }
  rek(idx + 1, lowrnext, lowcnext, highrnext, highcnext, prevnext, nextnext);
}

int main(){
  scanf("%d%d", &n, &m);
  m--;
  for(int i = n, mnow = m; i > 1; i >>= 1){
    int j = (i * i) >> 2;
    int cell = mnow / j;
    v.push_back(cell);
    mnow %= j;
  }
  rek(0, 1, 1, n, n, 1, 2);

  return 0;
}
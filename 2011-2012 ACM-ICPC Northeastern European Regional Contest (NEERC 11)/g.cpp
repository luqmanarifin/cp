#include <bits/stdc++.h>

using namespace std;

const string NAME = "gcd";

const int N = 10000;
bitset<N + 5> prim;
vector<int> pnum[5];
void sieve(){
  prim.set(); prim[0] = prim[1] = false;
  for(int i = 2;i <= N; ++i){
    if(prim[i]){
      int tmp = i * i;
      while(tmp <= N){
        prim[tmp] = false;
        tmp += i;
      }
      pnum[0].push_back(i);
    }
  }
}

void gen(){
  for(int i = 1;i < 5; ++i){
    int now = 1;
    for(int j = 0;j < i; ++j){
      now *= pnum[0][j];
    }

    for(int j = i;; ++j){
      now *= pnum[0][j];
      if(now > N) break;
      pnum[i].push_back(now);
      now /= pnum[0][j - i];
    }
  }
}

int main() {
#ifndef LOCAL
  freopen((NAME + ".in").c_str(), "r", stdin);
  freopen((NAME + ".out").c_str(), "w", stdout);
#endif

  sieve();
  gen();
  int n;
  scanf("%d", &n);
  int ans = 0;
  for(int i = 0;i < 5; ++i){
    int kali = (i & 1) ? -1 : 1;
    ans += kali * (upper_bound(pnum[i].begin(), pnum[i].end(), n) - pnum[i].begin());
  }
  // for (auto it : kurang) {
  //   printf("%d ", it);
  //   if (it > n) break;
  // }
  // printf("\n");

  printf("%d\n", ans);
#ifndef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif

  return 0;
}

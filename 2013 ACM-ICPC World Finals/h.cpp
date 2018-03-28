#include <bits/stdc++.h>
using namespace std;
const int N = 505, C = 505;

const int INF = 1e9;
int ar[N];
int countPref[C][N];
int RMinQ[N][10], RMaxQ[N][10];

bool invalidRange[N][N];
bool validRange[N][N];

int cost[N][N];
int dp[N];
int n;

inline void preCountPref(){
  for(int i = 1;i < C; ++i){
    for(int j = 1;j <= n; ++j){
      countPref[i][j] = countPref[i][j - 1] + (ar[j] <= i);
    }
  }
}

inline void preRMQ(){
  for(int i = 1;i <= n; ++i){
    RMinQ[i][0] = RMaxQ[i][0] = ar[i];
  }

  for(int i = 1;(1 << i) < n; ++i){
    for(int j = 1;j + (1 << i) - 1 <= n; ++j){
      RMinQ[j][i] = min(RMinQ[j][i-1], RMinQ[j + (1 << (i - 1))][i-1]);
      RMaxQ[j][i] = max(RMaxQ[j][i-1], RMaxQ[j + (1 << (i - 1))][i-1]);
    }
  }
}

int mins(int l, int r){
  int bits = __builtin_clz(r - l + 1) ^ 31;
  return min(RMinQ[l][bits], RMinQ[r - (1 << bits) + 1][bits]);
}
int maks(int l, int r){
  int bits = __builtin_clz(r - l + 1) ^ 31;
  return max(RMaxQ[l][bits], RMaxQ[r - (1 << bits) + 1][bits]);
}

inline void preInvalidRange(){
  int cnt[C];
  memset(cnt, 0, sizeof cnt);
  int pointer = 1;
  for(int i = 1;i <= n; ++i){
    cnt[ar[i]]++;
    while(cnt[ar[i]] > 1){
      for(int j = pointer; j >= 1; --j){
        for(int k = i;k <= n && !invalidRange[j][k]; ++k){
          invalidRange[j][k] = true;
        }
      }
      cnt[ar[pointer]]--;
      pointer++;
    }
  }
}

inline bool cekAwal(){
  multiset<int, greater<int> > ms;
  for(int i = 1;i <= n; ++i){
    ms.insert(ar[i]);
  }
  int last = INF;
  while(!ms.empty()){
    int now = *(ms.begin()); ms.erase(ms.begin());
    if(last == now) return false;
    last = now;
    for(int i = now - 1;i >= 1; --i){
      if(!ms.count(i)) return false;
      ms.erase(ms.find(i));
    }
  }
  return true;
}

inline void preValidRange(){
  for(int i = 1;i <= n; ++i){
    for(int j = i;j <= n; ++j){
      int banyak = j - i + 1;
      if(!invalidRange[i][j] && mins(i, j) == 1 && maks(i, j) == banyak){
        validRange[i][j] = true;
      }
    }
  }
}

inline int rek(int l, int r){
  if(l == r) return cost[l][r] = 0;
  if(cost[l][r] != INF) return cost[l][r];
  int &ret = cost[l][r];
  for(int i = l; i < r; ++i){
    int minkiri = mins(l, i);
    int minkanan = mins(i + 1,r);
    assert(minkiri != minkanan);
    int cost_merge = INF;
    if(minkiri < minkanan){
      cost_merge = r - l + 1 - (countPref[minkanan - 1][i] - countPref[minkanan - 1][l - 1]);
    }
    else{
      cost_merge = r - l + 1 - (countPref[minkiri - 1][r] - countPref[minkiri - 1][i]);
    }
    //fprintf(stderr, "REK(%d,%d,%d): %d %d %d\n", l, i, r, minkiri, minkanan, cost_merge);
    ret = min(ret, rek(l, i) + rek(i + 1, r) + cost_merge);
  }
  return ret;
}

int main(){
  scanf("%d", &n);
  for(int i = 1;i <= n; ++i) scanf("%d", &ar[i]);
  // if(!cekAwal()){
  //   puts("impossible");
  //   return 0;
  // }
  fill(dp, dp + n + 1, INF);
  preCountPref();
  preRMQ();
  preInvalidRange();
  preValidRange();
  for(int i = 1;i <= n; ++i) fill(cost[i], cost[i] + n + 1, INF);
  for(int i = 1;i <= n; ++i){
    for(int j = i;j <= n; ++j){
      if(invalidRange[i][j]) continue;
      //fprintf(stderr, "VALID RANGE %d %d\n", i, j);
      rek(i, j);
    }
  }
  // for(int i = 1;i <= n; ++i){
  //   for(int j = i;j <= n; ++j){
  //     fprintf(stderr, "INVALID : %d, VALID: %d, cost[%d][%d] : %d\n", invalidRange[i][j], validRange[i][j], i, j, cost[i][j]);
  //   }
  // }

  dp[0] = 0;
  for(int i = 1;i <= n; ++i){
    for(int j = 1;j <= i; ++j){
      if(validRange[j][i]) dp[i] = min(dp[i], dp[j - 1] + cost[j][i]);
    }
  }

  if(dp[n] == INF) puts("impossible");
  else printf("%d\n", dp[n]);

  return 0;
}
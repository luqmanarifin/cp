#include <bits/stdc++.h>

using namespace std;

const string NAME = "evacuation";
typedef long long LL;
typedef pair<int,int> pii;
#define fi first
#define se second
#define mp make_pair
#define pb push_back

const int N = 4000;
const LL INFL = 1e18;

LL dp[N + 5][N + 5][2];
pii loc[N + 5];
pii shelter[N + 5];
int n, m;

int ans[N + 5];
LL rek(int posn, int posm, bool udah){
  if(posn == n){
    if(posm == m - 1 && udah) return 0;
    return INFL;
  }
  if(n - posn + udah < m - posm) return INFL;
  if(posm == m) return INFL;
  if(dp[posn][posm][udah] != INFL) return dp[posn][posm][udah];
  LL &ret = dp[posn][posm][udah] = INFL;
  if(udah) ret = min(ret, rek(posn, posm + 1, 0));
  ret = min(ret, rek(posn + 1, posm, 1) + abs(loc[posn].fi - shelter[posm].fi));
  return ret;
}

void backtrack(int posn, int posm, int udah){
  if(posn == n) return;
  if(posm == m) return;
  if(udah && dp[posn][posm][udah] == dp[posn][posm + 1][0]) backtrack(posn, posm + 1, 0);
  else {
    ans[loc[posn].se] = shelter[posm].se + 1;
    backtrack(posn + 1, posm, 1);
  }
}

int main() {
#ifndef LOCAL
  freopen((NAME + ".in").c_str(), "r", stdin);
  freopen((NAME + ".out").c_str(), "w", stdout);
#endif
  scanf("%d", &n);
  for(int i = 0;i < n; ++i){
    scanf("%d", &loc[i].fi);
    loc[i].se = i;
  }
  scanf("%d", &m);
  for(int i = 0;i < m; ++i){
    scanf("%d", &shelter[i].fi);
    shelter[i].se = i;
  }
  for(int i = 0;i <= n; ++i) for(int j = 0;j <= m; ++j) fill(dp[i][j], dp[i][j] + 2, INFL);
  sort(loc, loc + n);
  sort(shelter, shelter + m);
  
  printf("%lld\n", rek(0, 0, 0));
  backtrack(0, 0, 0);
  for(int i = 0;i < n; ++i) printf("%d%c", ans[i], (i == n - 1) ? '\n' : ' ');
#ifndef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}

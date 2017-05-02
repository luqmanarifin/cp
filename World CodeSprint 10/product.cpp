#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;
const long long inf = 2e9;

// ikut atau nggak - minimum maximum
long long dp[N][2][2], rev[N][2][2];
int a[N];
vector<int> edge[N];
long long ans;

void mini(long long& at, long long val) {
  at = min(at, val);
}

void maxi(long long& at, long long val) {
  at = max(at, val);
}

void dfs(int now, int bef) {
  for (auto it : edge[now]) {
    if (it == bef) continue;
    dfs(it, now);
  }
  dp[now][0][0] = inf;
  dp[now][0][1] = -inf;
  dp[now][1][0] = dp[now][1][1] = a[now];
  for (auto it : edge[now]) {
    if (it == bef) continue;
    mini(dp[now][0][0], dp[it][0][0]);
    mini(dp[now][0][0], dp[it][1][0]);
    maxi(dp[now][0][1], dp[it][0][1]);
    maxi(dp[now][0][1], dp[it][1][1]);
    
    mini(dp[now][1][0], dp[now][1][0] + dp[it][1][0]);
    maxi(dp[now][1][1], dp[now][1][1] + dp[it][1][1]);
  }
  //printf("now %d; mini %I64d %I64d; maxi %I64d %I64d\n", now, dp[now][0][0], dp[now][1][0], dp[now][0][1], dp[now][1][1]);
}

void reverse(int now, int bef) {
  //printf("reverse %d\n", now);
  vector<int> kid;
  for (auto it : edge[now]) {
    if (it == bef) continue;
    kid.push_back(it);
  }
  vector<long long> lef0[2], rig0[2];
  vector<long long> lef1[2], rig1[2];
  lef0[0].assign(kid.size(), inf);
  lef0[1].assign(kid.size(), -inf);
  rig0[0].assign(kid.size(), inf);
  rig0[1].assign(kid.size(), -inf);
  
  lef1[0].assign(kid.size(), 0);
  lef1[1].assign(kid.size(), 0);
  rig1[0].assign(kid.size(), 0);
  rig1[1].assign(kid.size(), 0);
  for (int i = 0; i < kid.size(); i++) {
    if (i) {
      lef0[0][i] = lef0[0][i-1];
      lef0[1][i] = lef0[1][i-1];
      
      lef1[0][i] = lef1[0][i-1];
      lef1[1][i] = lef1[1][i-1];
    }
    mini(lef0[0][i], min(dp[kid[i]][0][0], dp[kid[i]][1][0]));
    maxi(lef0[1][i], max(dp[kid[i]][0][1], dp[kid[i]][1][1]));
    //printf("kid %d\n", kid[i]);
    mini(lef1[0][i], lef1[0][i] + dp[kid[i]][1][0]);
    maxi(lef1[1][i], lef1[1][i] + dp[kid[i]][1][1]);
    //printf("kid %d done\n", kid[i]);
  }
  //puts("swipe left done");
  for (int i = (int) kid.size() - 1; i >= 0; i--) {
    if (i+1 < kid.size()) {
      rig0[0][i] = rig0[0][i+1];
      rig0[1][i] = rig0[1][i+1];
      
      rig1[0][i] = rig1[0][i+1];
      rig1[1][i] = rig1[1][i+1];
    }
    mini(rig0[0][i], min(dp[kid[i]][0][0], dp[kid[i]][1][0]));
    maxi(rig0[1][i], max(dp[kid[i]][0][1], dp[kid[i]][1][1]));
    
    mini(rig1[0][i], rig1[0][i] + dp[kid[i]][1][0]);
    maxi(rig1[1][i], rig1[1][i] + dp[kid[i]][1][1]);
  }
  //puts("swipe right done");
  //printf("kid size %d\n", kid.size());
  for (int i = 0; i < kid.size(); i++) {
    long long pos = max(rev[now][1][1], rev[now][0][1]), neg = min(rev[now][1][0], rev[now][0][0]);
    long long sumpos = rev[now][1][1], sumneg = rev[now][1][0];
    //printf("nomer %d\n", i);
    //printf("1 pos %I64d\n", pos);
    //printf("1 sumpos %I64d\n", sumpos);
    if (i) {
      mini(neg, lef0[0][i-1]);
      maxi(pos, lef0[1][i-1]);
      
      mini(sumneg, sumneg + lef1[0][i-1]);
      maxi(sumpos, sumpos + lef1[1][i-1]);
    }
    //printf("2 pos %I64d\n", pos);
    //printf("2 sumpos %I64d\n", sumpos);
    if (i+1 < kid.size()) {
      mini(neg, rig0[0][i+1]);
      maxi(pos, rig0[1][i+1]);
      
      mini(sumneg, sumneg + rig1[0][i+1]);
      maxi(sumpos, sumpos + rig1[1][i+1]);
    }
    //printf("3 pos %I64d\n", pos);
    //printf("3 sumpos %I64d\n", sumpos);
    rev[kid[i]][0][0] = min(neg, sumneg);
    rev[kid[i]][0][1] = max(pos, sumpos);
    rev[kid[i]][1][0] = min((long long) a[kid[i]], a[kid[i]] + sumneg);
    rev[kid[i]][1][1] = max((long long) a[kid[i]], a[kid[i]] + sumpos);
    mini(neg, sumneg);
    maxi(pos, sumpos);
    
    maxi(ans, neg * min(dp[kid[i]][0][0], dp[kid[i]][1][0]));
    maxi(ans, pos * max(dp[kid[i]][0][1], dp[kid[i]][1][1]));
  }
  //puts("solving done");
  for (auto it : kid) reverse(it, now);
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", a + i);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    edge[u].push_back(v);
    edge[v].push_back(u);
  }
  dfs(1, 0);
  //puts("dfs done");
  rev[1][0][0] = inf;
  rev[1][0][1] = -inf;
  rev[1][1][0] = rev[1][1][1] = a[1];
  reverse(1, 0);
  cout << ans << endl;
  return 0;
}

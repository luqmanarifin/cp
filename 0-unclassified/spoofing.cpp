#include <bits/stdc++.h>

using namespace std;

const int N = 16;
const long long inf = 1e18;

long long dp[N][1 << N];
long long val[N][1 << N];
int last[N][1 << N];
vector<int> edge[N];

void add(int u, int v) {
  edge[u].push_back(v);
  edge[v].push_back(u);
}

int n = 16;

long long ans, col = inf;
int deep;

void entry(int mask) {
  if(dp[0][mask] < ans) {
    ans = dp[0][mask];
    col = val[0][mask];
    deep = mask;
  } else if(dp[0][mask] == ans && val[0][mask] < col) {
    deep = mask;
    col = val[0][mask];
  }
}

void backtrack(int now, int mask) {
  //printf("%d %d\n", now, mask);
  if(now == n - 1 && mask == 0) {
    return;
  }
  backtrack(last[now][mask], mask ^ (1 << last[now][mask]));
  printf("%c", 'A' + now);
}

int main() {
  for(int i = 0; i < n / 2; i++) {
    add(i, i + n / 2);
  }
  for(int i = 0; i < n / 2 - 1; i++) {
    add(i, i + n / 2 + 1);
  }
  for(int i = 1; i < n / 2; i++) {
    add(i, i + n / 2 - 1);
  }
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < (1 << n); j++) {
      dp[i][j] = val[i][j] = inf;
    }
  }
  queue<pair<int, int>> q;
  dp[n - 1][0] = 0;
  val[n - 1][0] = 0;
  q.emplace(n - 1, 0);
  
  for(int i = 0; i < n; i++) {
    for(auto it : edge[i]) {
      printf("%c - %c\n", i + 'A', it + 'A');
    }
  }
  
  while(!q.empty()) {
    int now, mask;
    tie(now, mask) = q.front();
    q.pop();
    long long nx = val[now][mask] * n + now;
    for(auto it : edge[now]) {
      int to = mask ^ (1 << now);
      if(dp[it][to] > dp[now][mask] + 1) {
        dp[it][to] = dp[now][mask] + 1;
        last[it][to] = now;
        q.emplace(it, to);
        val[it][to] = nx;
        //printf("%c to %c %d\n", now + 'A', it + 'A', dp[it][to]);
      } else if(dp[it][to] == dp[now][mask] + 1) {
        if(nx < val[it][to]) {
          last[it][to] = now;
          val[it][to] = nx;
          //printf("%c to %c %d\n", now + 'A', it + 'A', dp[it][to]);
        }
      }
    }
  }
  ans = inf;
  deep = -1;
  entry(0);
  entry(1);
  entry((1 << (n - 1)));
  entry((1 << (n - 1)) + 1);
  cout << "len " << ans << endl;
  backtrack(0, deep);
  return 0;
}

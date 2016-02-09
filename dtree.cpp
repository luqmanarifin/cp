#include <bits/stdc++.h>

using namespace std;

const int N = 5e4 + 5;

int n, k;
vector<int> edge[N];
long long ans;

vector<int> dfs(int now, int p) {
  vector<int> ret;
  ret.assign(k + 1, 0);
  ret[0] = 1;
  for(auto it : edge[now]) {
    if(it == p) {
      continue;
    } 
    vector<int> b = dfs(it, now);
    for(int i = 0; i < k; i++) {
      ret[i + 1] += b[i];
    }
    for(int i = 1; i <= k / 2; i++) {
      if(i - 1 == k - i - 1) {
        ans -= 1LL * b[i - 1] * (b[k - i - 1] - 1) / 2;
      } else {
        ans -= 1LL * b[i - 1] * b[k - i - 1];
      }
      //printf("di %d min %d %d\n", now, b[i - 1], b[k - i - 1]);
    }
  }
  for(int i = 0; i <= k / 2; i++) {
    if(i == k - i) {
      ans += 1LL * ret[i] * (ret[k - i] - 1) / 2;
    } else {
      ans += 1LL * ret[i] * ret[k - i];
    }
    //printf("di %d add %d %d\n", now, ret[i], ret[k - i]);
  }
  /*
  printf("node %d: ", now);
  for(auto it : ret) {
    printf("%d ", it);
  }
  printf("\n");
  */
  return ret;
}

int main() {
  scanf("%d %d", &n, &k);
  int m = n - 1;
  while(m--) {
    int u, v;
    scanf("%d %d", &u, &v);
    edge[u].push_back(v);
    edge[v].push_back(u);
  }
  dfs(1, -1);
  cout << ans << endl;
  return 0;
}

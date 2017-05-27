#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

vector<int> edge[N];
int a[N];
long long ans[N];
vector<pair<int, int>> st;

void dfs(int now, long long cur) {
  vector<pair<int, int>> rem;
  int cnt = 0;
  while (st.size() && st.back().first > a[now]) {
    rem.push_back(st.back());
    cur -= 1LL * st.back().first * st.back().second;
    cnt += st.back().second;
    st.pop_back();
  }
  cur += 1LL * a[now] * (cnt + 1);
  st.emplace_back(a[now], cnt + 1);
  
  ans[now] = cur;
  for (auto it : edge[now]) dfs(it, cur);
  
  cur -= 1LL * st.back().first * st.back().second;
  st.pop_back();
  while (rem.size()) {
    cur += 1LL * rem.back().first * rem.back().second;
    st.push_back(rem.back());
    rem.pop_back();
  }
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 2; i <= n; i++) {
    int p;
    scanf("%d", &p);
    edge[p].push_back(i);
  }
  for (int i = 1; i <= n; i++) scanf("%d", a + i);
  dfs(1, 0);
  for (int i = 1; i <= n; i++) printf("%lld ", ans[i]);
  return 0;
}

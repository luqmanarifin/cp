#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

vector<int> child[N];
int lim;

int dfs(int now) {
  vector<int> num;
  for(auto it : child[now]) {
    num.push_back(dfs(it));
  }
  sort(num.begin(), num.end());
  int del = max(0, (int) num.size() - lim);
  int ret = 1;
  for(int i = del; i < num.size(); i++) {
    ret += num[i];
  }
  return ret;
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for(int i = 2; i <= n; i++) {
    int papa;
    scanf("%d", &papa);
    child[papa].push_back(i);
  }
  int l = 0, r = n;
  while(l < r) {
    lim = (l + r) >> 1;
    if(m <= dfs(1)) r = lim;
    else l = lim + 1;
  }
  cout << l << endl;
  return 0;
}

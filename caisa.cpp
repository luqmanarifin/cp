#include <bits/stdc++.h>

using namespace std;

const int N = 2e6 + 100;
const int inf = 1e9;

bool is[N];
int id[N];
vector<int> prime;
vector<int> edge[N];
vector<int> s[N];
int a[N];
int ans[N];
int val[N];

void sikat(int now, int prev) {
  //printf("%d %d\n", now, prev);
  int v = a[now];
  int ret = -1, value = -1;
  vector<int> factors;
  for(int i = 0; prime[i] * prime[i] <= v; i++) {
    if(v % prime[i] == 0) {
      //printf("%d %d\n", a[now], prime[i]);
      factors.push_back(i);
      if(s[i].size() && val[s[i].back()] > value) {
        ret = s[i].back();
        value = val[s[i].back()];
      }
      s[i].push_back(now);
      while(v % prime[i] == 0) v /= prime[i];
    }
  }
  if(v != 1) {
    //printf("%d %d\n", a[now], v);
    assert(is[v] == false);
    factors.push_back(id[v]);
    if(s[id[v]].size() && val[s[id[v]].back()] > value) {
      ret = s[id[v]].back();
      value = val[s[id[v]].back()];
    }
    s[id[v]].push_back(now);
  }
  ans[now] = ret;
  for(auto it : edge[now]) {
    if(it == prev) {
      continue;
    }
    sikat(it, now);
  }
  for(auto it : factors) {
    s[it].pop_back();
  }
}

int main() {
  for(int i = 2; i < N; i++) {
    if(!is[i]) {
      id[i] = prime.size();
      prime.push_back(i);
      for(long long j = 1LL * i * i; j < N; j += i) {
        is[j] = 1;
      } 
    }
  }
  int n, query;
  scanf("%d %d", &n, &query);
  for(int i = 1; i <= n; i++) {
    scanf("%d", a + i);
  }
  int m = n - 1;
  while(m--) {
    int a, b;
    scanf("%d %d", &a, &b);
    edge[a].push_back(b);
    edge[b].push_back(a);
  }
  for(int i = 0; i < N; i++) {
    val[i] = inf;
  }
  queue<int> q;
  q.push(1);
  val[1] = 0;
  while(!q.empty()) {
    int now = q.front();
    q.pop();
    for(auto it : edge[now]) {
      if(val[now] + 1 < val[it]) {
        val[it] = val[now] + 1;
        q.push(it);
      }
    }
  }
  sikat(1, -1);
  while(query--) {
    int t, at, v;
    scanf("%d %d", &t, &at);
    if(t == 1) {
      printf("%d\n", ans[at]);
    } else {
      scanf("%d", &v);
      a[at] = v;
      sikat(1, -1);
    }
  }
  
  return 0;
}

#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

bool is[N];
int p[N], to[N], from[N];
vector<int> edge[N];

int main() {
  for (int i = 2; i < N; i++) {
    if (!is[i]) {
      p[i] = i;
      for (long long j = 1LL * i * i; j < N; j += i) {
        is[j] = 1;
      }
    }
  }
  set<pair<int, int>> s;
  s.insert(make_pair(4, 2));
  for (int i = 3; i < N; i++) {
    while (!s.empty() && (s.begin())->first == i) {
      auto it = s.begin();
      s.insert(make_pair(it->first + it->second, it->second));
      s.erase(it);
    }
    
    auto it = s.end();
    it--;
    to[i] = it->first;
    
    if (is[i] == 0) {
      s.insert(make_pair(i + i, i));
    }
  }
  for (int i = 3; i <= 20; i++) printf("%d %d\n", i, to[i]);
  fill(from, from + N, N);
  for (int i = 3; i < N; i++) {
    if (to[i] < N) {
      from[to[i]] = min(from[to[i]], i);
      edge[to[i]].push_back(i);
    }
  }
  int n;
  scanf("%d", &n);
  int ans = N;
  for (auto it : edge[n]) {
    printf("it %d\n", it);
    ans = min(ans, from[it]);
  }
  cout << ans << endl;
  return 0;
}

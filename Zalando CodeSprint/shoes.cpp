#include <bits/stdc++.h>

using namespace std;

const int N = 5e4 + 5;

int cnt[N];

int main() {
  int k, m, n;
  scanf("%d %d %d", &k, &m, &n);
  while(n--) {
    int a;
    scanf("%d", &a);
    cnt[a]++;
  }
  vector<pair<int, int>> p;
  for(int i = 0; i < m; i++) {
    p.emplace_back(cnt[i], -i);
  }
  sort(p.begin(), p.end());
  reverse(p.begin(), p.end());
  for(int i = 0; i < k; i++) {
    printf("%d\n", -p[i].second);
  }
  return 0;
}
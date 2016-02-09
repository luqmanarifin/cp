#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int v[N][2];

int main() {
  int n, s;
  scanf("%d %d", &n, &s);
  for(int i = 0; i < n; i++) {
    char c; int at, val;
    scanf(" %c %d %d", &c, &at, &val);
    v[at][c == 'B'] += val;
  }
  int t = s;
  vector<pair<int, int>> sell, buy;
  for(int i = 0; i < N; i++) {
    if(v[i][0]) {
      sell.emplace_back(i, v[i][0]);
    }
  }
  for(int i = 0; i < N; i++) {
    if(v[i][1]) {
      buy.emplace_back(i, v[i][1]);
    }
  }
  sort(sell.begin(), sell.end());
  sort(buy.begin(), buy.end());
  reverse(buy.begin(), buy.end());
  for(int i = min(s, (int) sell.size()) - 1; i >= 0; i--) {
    printf("S %d %d\n", sell[i].first, sell[i].second);
  }
  for(int i = 0; i < buy.size() && i < s; i++) {
    printf("B %d %d\n", buy[i].first, buy[i].second);
  }
  return 0;
}

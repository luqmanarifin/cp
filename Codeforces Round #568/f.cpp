#include <bits/stdc++.h>

using namespace std;

const int MASK = 9;

int man[1 << MASK], inside[1 << MASK];
vector<pair<int, int>> pizza[1 << MASK];

int price = 2e9 + 1e8, got = -1, p = -1, q = -1;

void upd(int cur_price, int cur_got, int i, int j) {
  if (cur_got > got) {
    got = cur_got;
    price = cur_price;
    p = i;
    q = j;
  } else if (cur_got == got) {
    if (cur_price < price) {
      price = cur_price;
      p = i;
      q = j;
    }
  }
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    int v;
    scanf("%d", &v);
    int mask = 0;
    while (v--) {
      int k;
      scanf("%d", &k);
      k--;
      mask |= (1 << k);
    }
    man[mask]++;
  }
  for (int i = 0; i < m; i++) {
    int wow, v;
    scanf("%d %d", &wow, &v);
    int mask = 0;
    while (v--) {
      int k;
      scanf("%d", &k);
      k--;
      mask |= (1 << k);
    }
    pizza[mask].emplace_back(wow, i);
  }
  for (int i = 0; i < (1 << MASK); i++) {
    sort(pizza[i].begin(), pizza[i].end());
  }
  for (int i = 0; i < (1 << MASK); i++) {
    for (int j = 0; j < (1 << MASK); j++) {
      if ((j & i) == i) {
        inside[j] += man[i];
      }
    }
  }
  int price = 2e9 + 1e8, got = -1;
  for (int i = 0; i < (1 << MASK); i++) {
    for (int j = i; j < (1 << MASK); j++) {
      if (i == j) {
        if (pizza[i].size() >= 2) {
          int cur_price = pizza[i][0].first + pizza[i][1].first;
          int cur_got = inside[i];
          upd(cur_price, cur_got, pizza[i][0].second, pizza[i][1].second);
        }
      } else {
        if (pizza[i].size() >= 1 && pizza[j].size() >= 1) {
          int cur_price = pizza[i][0].first + pizza[j][0].first;
          int cur_got = inside[i | j];
          upd(cur_price, cur_got, pizza[i][0].second, pizza[j][0].second);
        }
      }
    }
  }
  printf("%d %d\n", p + 1, q + 1);
  return 0;
}

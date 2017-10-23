#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

set<pair<long long, int>> s[N];

int cnt_all;
set<int> ada;

void remove_taxi(int at, pair<long long, int> v) {
  cnt_all--;
  s[at].erase(v);
  if (s[at].size() == 0) ada.erase(at);
}

void add_taxi(int at, pair<long long, int> v) {
  cnt_all++;
  s[at].insert(v);
  if (s[at].size() == 1) ada.insert(at);
}

pair<long long, int> get_taxi(int at) {
  auto it = *(s[at].begin());
  return it;
}

int main() {
  // time (minus) - di - id_taxi
  priority_queue<tuple<long long, int, int> > pq;

  int n, k, m;
  scanf("%d %d %d", &n, &k, &m);
  for (int i = 1; i <= k; i++) {
    int x;
    scanf("%d", &x);
    add_taxi(x, {0, i});
  }
  long long now = 0;
  vector<tuple<long long, int, int>> qq;
  while (m--) {
    long long t;
    int a, b;
    scanf("%lld %d %d", &t, &a, &b);
    qq.emplace_back(t, a, b);
  }
  for (auto it : qq) {
    long long t;
    int a, b;
    tie(t, a, b) = it;
    while (!pq.empty() && -get<0>(pq.top()) <= t) {
      long long time;
      int at, id;
      tie(time, at, id) = pq.top();
      time = -time;
      pq.pop();

      add_taxi(at, {time, id});
    }
    now = max(now, t);
    if (cnt_all == 0) {
      long long time;
      int at, id;
      tie(time, at, id) = pq.top();
      time = -time;
      pq.pop();

      add_taxi(at, {time, id});
      now = max(now, time);

      while (!pq.empty() && -get<0>(pq.top()) <= now) {
        tie(time, at, id) = pq.top();
        time = -time;
        pq.pop();

        add_taxi(at, {time, id});
      }
    }
    assert(cnt_all > 0);

    // d, time, id, at
    tuple<int, long long, int, int> cur = make_tuple(N, N, N, N);
    
    // get-taxi kiri
    auto j = ada.lower_bound(a);
    if (j != ada.end()) {
      int l = *j;
      auto it = get_taxi(l);
      cur = min(cur, make_tuple(l - a, it.first, it.second, l));
    }

    // get-taxi kanan
    if (j != ada.begin()) {
      j--;
      int l = *j;
      auto it = get_taxi(l);
      cur = min(cur, make_tuple(a - l, it.first, it.second, l));
    }

    int d, id, at;
    long long time;
    tie(d, time, id, at) = cur;
    remove_taxi(at, {time, id});
    //printf("%d %lld %d %d\n", d, time, id, at);
    //printf("dia available %lld\n", now + d + abs(b - a));
    pq.emplace(-(now + d + abs(b - a)), b, id);
    printf("%d %lld\n", id, now + d - t);
  } 

  return 0;
}
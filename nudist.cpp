#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const double eps = 1e-12;

bool fort[N];
bool yes[N];
int cur[N], n;

vector<int> edge[N];

bool equal(double a, double b) {
  return abs(a - b) < eps;
}

bool can(double rate) {
  //cerr << "rate : " << rate << endl;
  for(int i = 1; i <= n; i++) {
    yes[i] = !fort[i];
  }
  for(int i = 1; i <= n; i++) {
    cur[i] = 0;
    for(auto it : edge[i]) {
      if(yes[it]) {
        cur[i]++;
      }
    }
  }
  priority_queue<pair<double, int>> pq;
  for(int i = 1; i <= n; i++) {
    pq.emplace((double) -cur[i] / edge[i].size(), i);
  }
  while(!pq.empty()) {
    double t; int now;
    tie(t, now) = pq.top();
    t = -t;
    pq.pop();
    if(!equal(t, (double) cur[now] / edge[now].size()) || !yes[now]) {
      continue;
    }
    //cerr << t << ' ' << now << endl;
    if(t + eps < rate) {
      yes[now] = 0;
      for(auto it : edge[now]) {
        if(yes[it]) {
          cur[it]--;
          pq.emplace((double) -cur[it] / edge[it].size(), it);
        }
      }
    } else {
      break;
    }
  }
  for(int i = 1; i <= n; i++) {
    if(yes[i]) {
      return 1;
    }
  }
  return 0;
}

int main() {
  int m, k;
  scanf("%d %d %d", &n, &m, &k);
  for(int i = 0; i < k; i++) {
    int a;
    scanf("%d", &a);
    fort[a] = 1;
  }
  while(m--) {
    int a, b;
    scanf("%d %d", &a, &b);
    edge[a].push_back(b);
    edge[b].push_back(a);
  }
  double l = 0.0, r = 1.0;
  for(int it = 0; it < 50; it++) {
    double mid = (l + r) / 2;
    if(can(mid)) {
      l = mid;
    } else {
      r = mid;
    }
  }
  assert(can(l));
  int ans = 0;
  for(int i = 1; i <= n; i++) {
    ans += yes[i];
  }
  printf("%d\n", ans);
  for(int i = 1; i <= n; i++) {
    if(yes[i]) {
      printf("%d ", i);
    }
  }
  return 0;
}

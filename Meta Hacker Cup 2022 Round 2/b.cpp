#include <bits/stdc++.h>

using namespace std;

const int N = 2e6 + 5;
const long long mod = 1e9 + 7;

int x[N], y[N], a[N], b[N], K;
vector<long long> best[N];

vector<int> in[N], out[N];

void process(int t) {
  // minus biar gede duluan
  multiset<long long> cur;
  vector<pair<int, int>> sort_in; // i
  vector<pair<int, int>> sort_out; // j
  set<int> timeline;
  for (auto it : in[t]) {
    sort_in.emplace_back(y[it], it);
    timeline.insert(y[it]);
  }
  for (auto it : out[t]) {
    sort_out.emplace_back(x[it], it);
    timeline.insert(x[it]);
  }

  sort(sort_in.begin(), sort_in.end());
  sort(sort_out.begin(), sort_out.end());
  int i = 0, j = 0;
  for (auto val : timeline) {
    // process out
    for (; j < sort_out.size() && sort_out[j].first <= val; j++) {
      auto it = cur.begin();
      for (int k = 0; k < K && it != cur.end(); k++, it++) {
        best[sort_out[j].second].push_back(-(*it) + x[sort_out[j].second]);
      }
      if (best[sort_out[j].second].size() < K) {
        best[sort_out[j].second].push_back(0);
      }
    }

    // process in
    for (; i < sort_in.size() && sort_in[i].first <= val; i++) {
      for (auto it : best[sort_in[i].second]) {
        cur.insert(-(it - y[sort_in[i].second]));
      }
    }
  }
}


int main() {
  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    int n;
    scanf("%d %d", &n, &K);
    set<int> days;
    for (int i = 0; i < n; i++) {
      scanf("%d %d %d %d", a + i, b + i, x + i, y + i);
      days.insert(a[i]);
      days.insert(b[i]);
    }
    map<int, int> day_mapping;
    int cnt = 0;
    for (auto it : days) {
      day_mapping[it] = cnt;
      cnt++;
    }
    for (int i = 0; i < n; i++) {
      in[day_mapping[b[i]]].push_back(i);
      out[day_mapping[a[i]]].push_back(i);
    }
    for (int i = 0; i < cnt; i++) process(i);
    
    multiset<long long> cans;
    for (int i = 0; i < n; i++) {
      for (auto it : best[i]) {
        // printf("best %d: %d\n", i + 1, it);
        cans.insert(-it);
      }
    }
    long long ans = 0;
    auto it = cans.begin();
    for (int i = 0; i < K && it != cans.end(); i++, it++) {
      ans += -(*it);
      ans %= mod;
      // printf("adding %lld\n", *it);
    }
    printf("Case #%d: %lld\n", tt, ans);

    // clear
    for (int i = 0; i < n; i++) {
      best[i].clear();
    }
    for (int i = 0; i < cnt; i++) {
      in[i].clear();
      out[i].clear();
    }
    cerr << tt << " done!" << endl;
  }

  return 0;
}

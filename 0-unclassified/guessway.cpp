#include <bits/stdc++.h>

using namespace std;

const long long inf = 1e18;

bool intersect(pair<long long, long long> a, pair<long long, long long> b) {
  if(a.first > b.first) swap(a, b);
  return b.first <= a.second;
} 

pair<long long, long long> cut(pair<long long, long long> a, pair<long long, long long> b) {
  if(a.first > b.first) swap(a, b);
  return make_pair(b.first, min(a.second, b.second));
} 

int main() {
  int h, q;
  scanf("%d %d", &h, &q);
  set<pair<long long, long long>> s;
  s.insert(make_pair(1LL << (h - 1), (1LL << h) - 1));
  while(q--) {
    int i, ans;
    long long l, r;
    scanf("%d %I64d %I64d %d", &i, &l, &r, &ans);
    for(int it = i + 1; it <= h; it++) {
      l = l << 1;
      r = r << 1 | 1;
    }
    vector<pair<long long, long long>> in, out;
    if(ans == 1) {
      auto it = s.upper_bound(make_pair(l, inf));
      if(it != s.begin()) {
        it--;
      }
      while(it != s.end()) {
        if(r < it->first) break;
        if(intersect(*it, {l, r})) {
          in.push_back(cut(*it, {l, r}));
        }
        it++;
      }
      s.clear();
      for(auto z : in) s.insert(z);
      
    } else {
      auto it = s.upper_bound(make_pair(l, inf));
      if(it != s.begin()) {
        it--;
      }
      while(it != s.end()) {
        if(r < it->first) break;
        if(intersect(*it, {l, r})) {
          out.push_back(*it);
          auto c = cut(*it, {l, r});
          //printf("%I64d %I64d\n", c.first, c.second);
          if(c.first != it->first) {
            in.emplace_back(it->first, c.first - 1);
          }
          if(c.second != it->second) {
            in.emplace_back(c.second + 1, it->second);
          }
        }
        it++;
      }
      for(auto z : out) s.erase(z);
      for(auto z : in) s.insert(z);
    }
  }
  if(s.empty()) {
    puts("Game cheated!");
  } else if(s.size() > 1 || s.begin()->first != s.begin()->second) {
    puts("Data not sufficient!");
  } else {
    cout << s.begin()->first << endl;
  }
  return 0;
}

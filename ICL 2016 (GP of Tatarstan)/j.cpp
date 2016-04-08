#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  set<pair<int, int>> s;
  while(n--) {
    int v, p;
    scanf("%d", &v);
    if(v < 0) {
      v = -v;
      auto it = s.lower_bound(make_pair(v + 1, -1));
      if(it != s.begin()) {
        it--;
        if(it->first <= v && v <= it->second) {
          vector<pair<int, int>> add;
          if(it->first < v) {
            add.emplace_back(it->first, v - 1);
          }
          if(v < it->second) {
            add.emplace_back(v + 1, it->second);
          }
          s.erase(it);
          for(auto i : add) s.insert(i);
        }
      }
    } else {
      scanf("%d", &p);
      auto it = s.lower_bound(make_pair(v + 1, -1));
      int from = v;
      if(it != s.begin()) {
        it--;
        from = max(from, it->second + 1);
        it++;
      }
      int to = from + p - 1;
      if(it != s.end()) {
        to = min(to, it->first - 1);
      }
      printf("%d %d\n", from, to);
      
      vector<pair<int, int>> del;
      if(it != s.end()) {
        if(to + 1 == it->first) {
          del.push_back(*it);
          to = it->second;
        }
      }
      if(it != s.begin()) {
        it--;
        if(it->second + 1 == from) {
          del.push_back(*it);
          from = it->first;
        }
      }
      for(auto i : del) {
        s.erase(i);
      }
      s.insert(make_pair(from, to));
    }
  }
  return 0;
}
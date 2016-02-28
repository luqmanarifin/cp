#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int a[N], b[3], n;
vector<pair<int, int>> p, r;

bool can(int t) {
  multiset<int> s;
  for(int i = 0; i < n; i++) s.insert(a[i]);
  while(t-- && !s.empty()) {
    bool ada[3] = {};
    auto it = s.end();
    it--;
    for(auto mus : p) {
      if(mus.first >= *it) {
        s.erase(it);
        for(int i = 0; i < 3; i++) {
          if(mus.second & (1 << i)) {
            ada[i] = 1;
          }
        }
        break;
      }
    }
    int free = !ada[0] + !ada[1] + !ada[2];
    if(!s.empty()) {
      it = s.end();
      it--;
      if(*it <= b[0]) {
        while(free-- && !s.empty()) {
          it = s.end();
          it--;
          s.erase(it);
        }
        continue;
      }
    }
    for(auto mus : r) {
      bool kos = 1;
      for(int i = 0; i < 3; i++) {
        if((mus.second & (1 << i)) && ada[i]) {
          kos = 0;
          break;
        }
      }
      if(kos) {
        it = s.upper_bound(mus.first);
        if(it != s.begin()) {
          it--;
          s.erase(it);
          for(int i = 0; i < 3; i++) {
            if(mus.second & (1 << i)) {
              ada[i] = 1;
            }
          }
        }
      }
    }
  }
  return s.empty();
}

int main() {
  scanf("%d", &n);
  for(int i = 0; i < 3; i++) {
    scanf("%d", b + i);
  }
  for(int i = 0; i < n; i++) {
    scanf("%d", a + i);
    if(a[i] > b[0] + b[1] + b[2]) {
      puts("-1");
      return 0;
    }
  }
  sort(b, b + 3);
  sort(a, a + n);
  for(int i = 0; i < (1 << 3); i++) {
    int sum = 0;
    for(int j = 0; j < 3; j++) {
      if(i & (1 << j)) {
        sum += b[j];
      }
    }
    p.emplace_back(sum, i);
  }
  sort(p.begin(), p.end());
  r = p;
  reverse(r.begin(), r.end());
  
  int l = 1, r = n;
  while(l < r) {
    int mid = (l + r) >> 1;
    if(can(mid)) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  cout << l << endl;
  return 0;
}
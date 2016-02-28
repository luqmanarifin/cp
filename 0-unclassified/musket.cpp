#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int str[3], n, a, b, c;
multiset<int> s;

int best() {
  auto it = s.end();
  it--;
  return *it;
}

int del(int v) {
  auto it = s.upper_bound(v);
  if(it == s.begin()) return -1;
  it--;
  int ret = *it;
  s.erase(it);
  return ret;
}

bool can(int t) {
  //printf("%d can lah\n", t);
  multiset<int> rem = s;
  for(int i = 0; i < t; i++) {
    del(c);
  }
  for(int i = 0; i < t && !s.empty(); i++) {
    int now = best();
    if(now > b) {     // must use a + b
      assert(del(a + b) <= now);
    } else {
      del(a);
      del(b);
    }
  }
  bool good = s.empty();
  s = rem;
  return good;
}

int main() {
  scanf("%d", &n);
  for(int i = 0; i < 3; i++) {
    scanf("%d", str + i);
  }
  sort(str, str + 3);
  a = str[0];
  b = str[1];
  c = str[2];
  for(int i = 0; i < n; i++) {
    int v;
    scanf("%d", &v);
    s.insert(v);
  }
  int ans = 0;
  while(!s.empty()) {
    int now = best();
    if(now > a + b + c) {
      puts("-1");
      return 0;
    }
    if(now > b + c) {                 // must use a + b + c
      ++ans;
      del(now);
    } else if(now > a + c) {          // must use b + c
      ++ans;
      del(now);
      del(a);
    } else if(now > max(a + b, c)) {  // must use a + c
      ++ans;
      del(now);
      del(b);
    } else {
      break;
    }
  }
  //puts("wajib done");
  int l = 0, r = s.size();
  while(l < r) {
    int mid = (l + r) >> 1;
    if(can(mid)) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  cout << ans + l << endl;
  return 0;
}

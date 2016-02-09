#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

struct bit {
public:
  bit(int _n) : n(_n) {
    at.resize(n + 1);
    update(0);
    update(n);
  }
  void update(int now) {
    int pos = now;
    for(; now <= n; now |= now + 1) {
      at[now] = max(at[now], pos);
    }
  }
  int get(int now) {
    int ret = 0;
    for(; now >= 0; now = (now & (now + 1)) - 1) {
      ret = max(ret, at[now]);
    }
    return ret;
  }
private:
  int n;
  vector<int> at;
};

void print(multiset<int> s) {
  for(auto it : s) printf("%d ", it);
  printf("\n");
}

int main() {
  int w, h, n;
  scanf("%d %d %d", &w, &h, &n);
  
  set<int> nexw;
  set<int> nexh;
  nexw.insert(0); nexw.insert(w);
  nexh.insert(0); nexh.insert(h);
  bit befw(w);
  bit befh(h);
  multiset<int> maxw; maxw.insert(w);
  multiset<int> maxh; maxh.insert(h);
  
  while(n--) {
    char s[5];
    int now;
    scanf("%s %d", s, &now);
    if(s[0] == 'V') {
      int upper = *nexw.upper_bound(now);
      int lower = befw.get(now);
      
      maxw.erase(maxw.find(upper - lower));
      maxw.insert(upper - now);
      maxw.insert(now - lower);
      
      nexw.insert(now);
      befw.update(now);
    } else {
      int upper = *nexh.upper_bound(now);
      int lower = befh.get(now);
      
      maxh.erase(maxh.find(upper - lower));
      maxh.insert(upper - now);
      maxh.insert(now - lower);
      
      nexh.insert(now);
      befh.update(now);
    }
    multiset<int>::iterator ww = maxw.end(); ww--;
    multiset<int>::iterator hh = maxh.end(); hh--;
    printf("%I64d\n", 1LL * *ww * *hh);
  }
  
  return 0;
}

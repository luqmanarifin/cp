#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

char junk[100];

struct bit {
public:
  bit(int _n) : n(_n) {
    num.resize(n + 1);
  }
  void add(int pos, long long val) {
    for(; pos <= n; pos |= pos + 1) {
      num[pos] += val;
    }
  }
  long long get(int pos) {
    long long ret = 0;
    for(; pos >= 0; pos = (pos & (pos + 1)) - 1) {
      ret += num[pos];
    }
    return ret;
  }
private:
  vector<long long> num;
  int n;
};

vector<int> at;
vector<int> bat[N];

int id(int a) {
  return lower_bound(at.begin(), at.end(), a) - at.begin();
}

int main() {
  int n, m;
  scanf("%s %d %d", junk, &n, &m);
  for(int i = 0; i < n; i++) {
    int c, w;
    scanf("%d %d", &c, &w);
    bat[c].push_back(w);
    at.push_back(w);
  }
  sort(at.begin(), at.end());
  vector<int> temp;
  for(int i = 0; i < at.size(); i++) {
    if(i && at[i] == at[i - 1]) continue;
    temp.push_back(at[i]);
  }
  at = temp;
  
  bit cnt(n);
  bit num(n);
  bit rcnt(n);
  bit rnum(n);
  long long ans = 0;
  for(int i = 1; i <= m; i++) {
    for(auto it : bat[i]) {
      int index = id(it);
      ans += abs(cnt.get(index) * it - num.get(index));
      ans += abs(rcnt.get(n - index) * it - rnum.get(n - index));
    }
    for(auto it : bat[i]) {
      int index = id(it);
      cnt.add(index, 1);
      num.add(index, it);
      rcnt.add(n - index, 1);
      rnum.add(n - index, it);
    }
  }
  printf("%lld\n", ans);
  return 0;
}

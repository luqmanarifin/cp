#include <bits/stdc++.h>

using namespace std;

const int pol = 1e8 + 5;

bitset<pol> is;
vector<int> p, num, ret;
long long power[30];

long long get(int b, int len) {
  assert(len / 2 + len % 2 == num.size());
  long long res = 0;
  for(int i = 0; i < len; i++) {
    res += 1LL * power[i] * num[min(i, len - i - 1)];
  }
  return res;
}

int main() {
  int k;
  scanf("%d", &k);
  while(k--) {
    int a;
    scanf("%d", &a);
    p.push_back(a);
  }
  sort(p.begin(), p.end());
  p.resize(distance(p.begin(), unique(p.begin(), p.end())));
  for(auto b : p) {
    power[0] = 1;
    for(int i = 1; i < 30; i++) {
      power[i] = power[i - 1] * b;
    }
    for(int len = 1; len < 30 && power[len - 1] + 1 < pol; len++) {
      num.clear();
      int h = len / 2 + len % 2;
      num.push_back(1);
      for(int i = 0; i < h - 1; i++) {
        num.push_back(0);
      }
      long long cur = get(b, len);
      while(cur < pol) {
        assert(cur >= 0);
        if(!is[cur]) {
          ret.push_back(cur);
          is[cur] = 1;
        }
        num.back()++;
        for(int i = num.size() - 1; i >= 0 && num[i] == b; i--) {
          if(i == 0) {
            goto cont;
          }
          num[i] = 0;
          num[i - 1]++;
        }
        cur = get(b, len);
      }
      cont:;
    }
  }
  ret.push_back(0);
  sort(ret.begin(), ret.end());
  ret.resize(distance(ret.begin(), unique(ret.begin(), ret.end())));
  int q;
  scanf("%d", &q);
  while(q--) {
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d\n", upper_bound(ret.begin(), ret.end(), b) - lower_bound(ret.begin(), ret.end(), a));
  }
  return 0;
}

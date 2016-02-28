#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N];
vector<pair<int, int>> raw;
int n;

class rmq {
public:
  rmq(int _n) : n(_n) {
    for(int i = 0; i < n; i++) {
      num[i][0] = a[i];
    }
    for(int j = 1; (1 << j) <= n; j++) {
      for(int i = 0; i + (1 << (j - 1)) < n; i++) {
        num[i][j] = __gcd(num[i][j - 1], num[i + (1 << (j - 1))][j - 1]);
      }
    }
  }
  int find(int l, int r) {
    assert(l <= r);
    int bit = __builtin_clz(r - l + 1) ^ 31;
    return __gcd(num[l][bit], num[r - (1 << bit) + 1][bit]);
  }
private:
  int n;
  int num[N][20];
};

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  rmq gcd(n);
  for(int i = 0; i < n; i++) {
    int j = i;
    while(j < n) {
      int now = gcd.find(i, j);
      int l = j, r = n - 1;
      while(l < r) {
        int mid = (l + r + 1) >> 1;
        if(gcd.find(i, mid) == now) {
          l = mid;
        } else {
          r = mid - 1;
        }
      }
      raw.emplace_back(now, l - j + 1);
      j = l + 1;
    }
  }
  sort(raw.begin(), raw.end());
  
  vector<pair<int, long long>> ret;
  for(auto it : raw) {
    if(ret.empty() || ret.back().first != it.first) {
      ret.push_back(it);
    } else {
      ret.back().second += it.second;
    }
  }
  
  int q;
  scanf("%d", &q);
  while(q--) {
    int num;
    scanf("%d", &num);
    int id = lower_bound(ret.begin(), ret.end(), make_pair(num, -1LL)) - ret.begin();
    if(id < ret.size() && ret[id].first == num) {
      printf("%I64d\n", ret[id].second);
    } else {
      puts("0");
    }
  }
  return 0;
}

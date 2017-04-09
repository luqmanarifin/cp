#include <bits/stdc++.h>

using namespace std;

const int N = 55;
const long long mod = 1e9 + 7;

class SubtreeSumHash {
public:
  vector<int> w;
  vector<int> edge[N];
  long long all, x;
  
  long long power(long long a, long long b) {
    if (a >= mod) a %= mod;
    if (b == 0) return 1;
    long long tmp = power(a, b / 2);
    tmp = tmp * tmp % mod;
    if (b & 1) tmp = tmp * a % mod;
    return tmp;
  }
  
  long long dfs(int now, int bef = -1) {
    long long tmp = 0;
    long long val = power(x, w[now]);
    for (auto it : edge[now]) {
      if (it == bef) continue;
      long long ret = dfs(it, now);
      long long mul = tmp * ret % mod;
      
      tmp += mul;
      tmp += (ret * val) % mod;
      tmp %= mod;
    }
    tmp = (tmp + val) % mod;
    all = (all + tmp) % mod;
    return tmp;
  }
  
  int count(vector<int> _w, vector<int> p, int _x) {
    w = _w;
    x = _x;
    for (int i = 0; i < p.size(); i++) {
      edge[i + 1].push_back(p[i]);
      edge[p[i]].push_back(i + 1);
    }
    dfs(0);
    return (int) all;
  }
};

/*
int main() {
  int l = 0;
  int r = 0;
  
  SubtreeSumHash SubtreeSumHash;
  cout << SubtreeSumHash.count() << endl;
  
  return 0;
}

*/
#include <bits/stdc++.h>

using namespace std;

const int N = 55;
const long long mod = 1e9 + 7;

class SubtreeSumHash {
public:
  vector<int> w;
  vector<int> edge[N], all;
  
  long long power(long long a, long long b) {
    if (a >= mod) a %= mod;
    if (b == 0) return 1;
    long long tmp = power(a, b / 2);
    tmp = tmp * tmp % mod;
    if (b & 1) tmp = tmp * a % mod;
    return tmp;
  }
  
  vector<long long> dfs(int now, int bef = -1) {
    vector<long long> tmp;
    for (auto it : edge[now]) {
      if (it == bef) continue;
      vector<long long> ret = dfs(it, now);
      vector<long long> mul;
      for (auto i : tmp) for (auto j : ret) mul.push_back(i + j);
      
      for (auto i : mul) tmp.push_back(i);
      for (auto i : ret) tmp.push_back(i + w[now]);
    }
    tmp.push_back(w[now]);
    for (auto it : tmp) all.push_back(it);
    return tmp;
  }
  
  int count(vector<int> _w, vector<int> p, int x) {
    w = _w;
    for (int i = 0; i < p.size(); i++) {
      edge[i + 1].push_back(p[i]);
      edge[p[i]].push_back(i + 1);
    }
    dfs(0);
    long long ans = 0;
    for (auto it : all) {
      ans += power(x, it);
      if (ans >= mod) ans -= mod;
    }
    return (int) ans;
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
#include <bits/stdc++.h>

using namespace std;

const int N = 3005;
const long long inf = 1e18;

class FiringEmployees {
public:
  vector<int> edge[N];
  long long a[N];
  
  long long solve(int now) {
    long long ret = a[now];
    for(auto it : edge[now]) {
      ret += solve(it);
    }
    ret = max(0LL, ret);
    return ret;
  }
  
  int fire(vector<int> man, vector<int> sal, vector<int> pro) {
    int n = man.size(); 
    for(int i = 0; i < n; i++) {
      edge[man[i]].push_back(i + 1);
      a[i + 1] = pro[i] - sal[i];
    }
    return solve(0);
  }
};
/*
int main() {
  int l = 0;
  int r = 0;
  FiringEmployees kelas;
  cout << kelas.fire() << endl;
  return 0;
}
*/
#include <bits/stdc++.h>

using namespace std;

class PrivateD2party {
public:
  int dfs(int now) {
    if(at[now]) return -1;
    if(done[now]) return 0;
    at[now] = 1;
    done[now] = 1;
    int ret = 1;
    if(a[now] != now) {
      ret += dfs(a[now]);
    }
    at[now] = 0;
    return ret;
  }
  
  int getsz(vector<int> _a) {
    a = _a;
    n = a.size();
    done.resize(n);
    at.resize(n);
    int ret = 0;
    for(int i = 0; i < n; i++) {
      ret += dfs(i);
    }    
    return ret;
  }
  int n;
  vector<int> done;
  vector<int> at;
  vector<int> a;
};
/*
int main() {
  vector<int> a = {3,2,1,0,5,4};
  
  PrivateD2party kelas;
  cout << kelas.getsz(a) << endl;
  
  return 0;
}
*/
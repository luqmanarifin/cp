#include <bits/stdc++.h>

using namespace std;

class FilipTheFrog {
public:
  int countReachableIslands(vector<int> num, int l) {
    int now = num[0];
    sort(num.begin(), num.end());
    int st = lower_bound(num.begin(), num.end(), now) - num.begin();
    int ret = 1;
    for(int i = st + 1; i < num.size(); i++) {
      if(abs(num[i] - num[i - 1]) <= l) {
        ret++;
      } else {
        break;
      }
    }
    for(int i = st - 1; i >= 0; i--) {
      if(abs(num[i] - num[i + 1]) <= l) {
        ret++;
      } else {
        break;
      }
    }
    return ret;
  }
  
};

/*
int main() {
  vector<int> a = {4, 7, 1, 3, 5};
  int l = 1;
  FilipTheFrog f;
  cout << f.countReachableIslands(a, l) << endl;
  return 0;
}
*/
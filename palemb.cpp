#include <bits/stdc++.h>

using namespace std;

const long long inf = 4e18;

vector<pair<int, int>> p;

long long find(int b) {
  long long ret = 0;
  for(auto it : p) {
    if(it.second < b) {
      ret += b - it.second;
    }
    if(b < it.first) {
      ret += it.first - b;
    }
  }
  return ret;
}

int main() {
  long long pokok = 0;
  int k, n;
  scanf("%d %d", &k, &n);
  while(n--) {
    char sa[3], sb[3];
    int a, b;
    scanf("%s %d %s %d", sa, &a, sb, &b);
    pokok += abs(a - b);
    if(sa[0] != sb[0]) {
      pokok++;
      if(a > b) swap(a, b);
      p.emplace_back(a, b);
    }
  }
  long long add = inf;
  int l = 0, r = 1000000000;
  while(l + 3 <= r) {
    int leftThird = l + (r - l) / 3;
    int rightThird = r - (r - l) / 3;
    //cout << leftThird << ' ' << rightThird << ' ' << find(leftThird) << ' ' << find(rightThird) << endl;
    if(find(leftThird) > find(rightThird)) {
      l = leftThird;
    } else {
      r = rightThird;
    }
  }
  for(int i = l; i <= r; i++) {
    add = min(add, find(i));
  }
  cout << pokok + add * 2 << endl;
  return 0;
}

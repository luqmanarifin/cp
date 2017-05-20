#include <bits/stdc++.h>

using namespace std;

const long long mod = 1e9 + 7;

int solution(vector<int> &a) {
  int n = a.size();
  long long ans = 0;
  for (int mid = 0; mid < n; mid++) {
    vector<int> lef, rig;
    for (int i = 0; i < mid; i++) if (a[i] > a[mid]) lef.push_back(a[i]);
    for (int i = mid + 1; i < n; i++) if (a[i] > a[mid]) rig.push_back(a[i]);
    sort(lef.begin(), lef.end());
    sort(rig.begin(), rig.end());
    long long slef = 0, srig = 0;
    int i = 0, j = 0;
    while (i < lef.size() && j < rig.size()) {
      if (lef[i] < rig[j]) {
        slef += srig + 1;
        slef %= mod;
        i++;
      } else if (lef[i] > rig[j]) {
        srig += slef + 1;
        srig %= mod;
        j++;
      } else {
        assert(0);
      }
    }
    while (i < lef.size()) {
      slef += srig + 1;
      slef %= mod;
      i++;
    }
    while (j < rig.size()) {
      srig += slef + 1;
      srig %= mod;
      j++;
    }
    ans += slef + srig + 1;
    ans %= mod;
  }
  return (int) ans;
}

int main() {


  return 0;
}

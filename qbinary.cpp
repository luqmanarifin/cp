#include <bits/stdc++.h>

using namespace std;

int ten[7], n;

int power(int a, int b) {
  int ret = 1;
  while(b--) {
    ret *= a;
  }
  return ret;
}

int get(int i) {
  return n / ten[i] % 10;
}

int main() {
  for(int i = 0; i < 7; i++) {
    ten[i] = power(10, i);
  }
  scanf("%d", &n);
  vector<int> ans;
  for(int t = 0; t < 15; t++) {
    int now = 0;
    for(int i = 0; i < 7; i++) {
      if(get(i) != 0) {
        now += ten[i];
        n -= ten[i];
      }
    }
    if(now != 0) {
      ans.push_back(now);
    }
  }
  
  cout << ans.size() << endl;
  for(auto it : ans) {
    printf("%d ", it);
  }
  printf("\n");
  return 0;
}

#include <bits/stdc++.h>

using namespace std;

int a[1005];
int n = 7;

bool changed() {
  bool done[n];
  memset(done, 0, sizeof(done));
  vector<vector<int>> num;
  for(int i = 0; i < n; i++) {
    if(!done[i]) {
      vector<int> tmp = {a[i]};
      done[i] = 1;
      int now = a[i];
      while(!done[now]) {
        done[now] = 1;
        now = a[now];
        tmp.push_back(now);
      }
      num.push_back(tmp);
    }
  }
  vector<int> ret;
  for(auto it : num) {
    sort(it.begin(), it.end());
    reverse(it.begin(), it.end());
    for(auto i : it) {
      ret.push_back(i);
    }
  }
  for(int i = 0; i < n; i++) {
    if(ret[i] != a[i]) {
      return 1;
    }
  }
  return 0;
}

int main() {
  for(int i = 0; i < n; i++) {
    a[i] = i;
  }
  int id = 0;
  do {
    if(!changed()) {
      printf("%d: ", ++id);
      for(int i = 0; i < n; i++) {
        printf("%d ", a[i] + 1);
      }
      printf("\n");
    }
  } while(next_permutation(a, a + n));
  
  return 0;
}

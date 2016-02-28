#include <bits/stdc++.h>

using namespace std;

const int N = 55;

int a[N];

int main() {
  int n;
  scanf("%d", &n);
  set<int> be;
  set<int> id;
  for(int i = 1; i <= n + 1; i++) {
    be.insert(i);
    if(i <= n) {
      id.insert(i);
    }
  }
  int p = 0;
  while(be.size() > 1) {
    int zero = 0;
    vector<int> idd, bee;
    for(auto it : id) {
      idd.push_back(it);
      printf("1 %d %d\n", it, p);
      fflush(stdout);
      
      int num;
      scanf("%d", &num);
      a[it] = num;
      if(num == 0) {
        zero++;
      }
    }
    int z = 0;
    for(auto it : be) {
      bee.push_back(it);
      if((it & (1 << p)) == 0) {
        z++;
      }
    }
    int chosen = (1 << p), ada = 1;
    if(zero != z) {
      chosen = 0;
      ada = 0;
    }
    for(auto it : idd) {
      if(a[it] != ada) {
        id.erase(it);
      }
    }
    for(auto it : bee) {
      if((it & (1 << p)) != chosen) {
        be.erase(it);
      }
    }
    p++;
  }
  printf("2 %d\n", *(be.begin()));
  fflush(stdout);
  return 0;
}

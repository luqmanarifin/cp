#include <bits/stdc++.h>

using namespace std;

map<int, int> mf, ms;
vector<int> first, second, third;

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    mf[a]++;
    first.push_back(a);
  }
  for(int i = 0; i < n - 1; i++) {
    int a;
    scanf("%d", &a);
    ms[a]++;
    second.push_back(a);
  }
  for(int i = 0; i < n - 2; i++) {
    int a;
    scanf("%d", &a);
    third.push_back(a);
  }
  for(int i = 0; i < n; i++) {
    if(mf[first[i]] > ms[first[i]]) {
      printf("%d\n", first[i]);
      break;
    }
  }
  mf.clear();
  ms.clear();
  for(auto it : second) {
    mf[it]++;
  }
  for(auto it : third) {
    ms[it]++;
  }
  for(auto it : second) {
    if(mf[it] > ms[it]) {
      printf("%d\n", it);
      break;
    }
  }
  return 0;
}
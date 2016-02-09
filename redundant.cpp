#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  set<int> s;
  while(n--) {
    int a;
    scanf("%d", &a);
    if(s.find(a) != s.end()) {
      puts("REDUNDANT");
    } else {
      puts("ADDED");
      s.insert(a);
    }
  }
  
  return 0;
}

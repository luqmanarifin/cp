#include <bits/stdc++.h>

using namespace std;

void print(multiset<int> a) {
  for (auto it : a) printf("%d ", it); printf("\n");
}

int main() {
  multiset<int> a;
  a.insert(2);
  print(a);
  a.insert(2);
  print(a);
  a.erase(a.find(2));
  print(a);


  return 0;
}

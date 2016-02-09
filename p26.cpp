#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  vector<int> a;
  scanf("%d", &n);
  while(n--) {
    int num;
    scanf("%d", &num);
    a.push_back(num);
  }
  sort(a.begin(), a.end());
  a.resize(distance(a.begin(), unique(a.begin(), a.end())));
  if(a.size() < 3) puts("-1");
  else printf("%d\n", a[2]);
  return 0;
}

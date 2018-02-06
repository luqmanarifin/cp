#include <bits/stdc++.h>

using namespace std;

const int MAX = 90e6;

bitset<MAX> is;
vector<int> p;

int main() {
  for (int i = 2; i < MAX; i++) {
    if (!is[i]) p.push_back(i);
    for (int j = 0; j < p.size() && i * p[j] < MAX; j++) {
      is[i * p[j]] = 1;
      if (i % p[j] == 0) break;
    }
  }
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    printf("%d\n", p[n-1]);
  }  
  return 0;
}

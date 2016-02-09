#include <bits/stdc++.h>

/**
 * If you see that I'm the one who understand you
 * Been here all along. So why can't you see--
 * You belong with me?
 **/

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  vector<int> a;
  for(int i = 0; i < n; i++) {
    int num;
    scanf("%d", &num);
    a.push_back(num);
  }
  sort(a.begin(), a.end());
  swap(a[0], a.back());
  for(auto it : a) printf("%d ", it);
  return 0;
}
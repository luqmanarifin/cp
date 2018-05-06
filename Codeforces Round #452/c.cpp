
#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  if (n % 4 == 0 || n % 4 == 3) {
    puts("0");
  } else {
    puts("1");
  }
  vector<int> ans;
  for (int i = n - 3; i >= 1; i -= 4) {
    ans.push_back(i + 1);
    ans.push_back(i + 2);
  }
  if (n % 4 == 2) {
    ans.push_back(1);
  }
  if (n % 4 == 3) {
    ans.push_back(3);
  }
  printf("%d", ans.size());
  for (auto it : ans) printf(" %d", it); printf("\n");
  return 0;
}

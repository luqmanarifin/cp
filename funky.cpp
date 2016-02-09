#include <bits/stdc++.h>

using namespace std;

vector<int> num;

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 1; ; i++) {
    if(i * (i + 1) / 2 > n) break;
    num.push_back(i * (i + 1) / 2);
  }
  for(auto it : num) {
    if(binary_search(num.begin(), num.end(), n - it)) {
      puts("YES");
      return 0;
    }
  }
  puts("NO");
  return 0;
}

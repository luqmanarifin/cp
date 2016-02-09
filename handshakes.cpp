#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

vector<int> p[N];
int ans[N];

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    p[a].push_back(i);
  }
  int rem = n;
  int i = 0, id = 0;
  while(rem > 0) {
    while(p[i].empty() && i >= 3) {
      i -= 3;
    }
    if(p[i].empty()) {
      puts("Impossible");
      return 0;
    }
    ans[id++] = p[i].back();
    p[i].pop_back();
    i++;
    rem--;
  }
  puts("Possible");
  for(int i = 0; i < n; i++) {
    printf("%d ", ans[i] + 1);
  }
  return 0;
}

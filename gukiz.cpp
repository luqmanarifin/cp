#include <bits/stdc++.h>

using namespace std;

const int N = 2005;

pair<int, int> p[N];
int ans[N];

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    p[i] = make_pair(a, i);
  }
  sort(p, p + n);
  reverse(p, p + n);
  for(int i = 0; i < n; i++) {
    int j = i;
    while(j + 1 < n && p[j + 1].first == p[j].first) {
      j++;
    }
    for(int k = i; k <= j; k++) {
      ans[p[k].second] = i + 1;
    }
    i = j;
  }
  for(int i = 0; i < n; i++) {
    printf("%d ", ans[i]);
  }
  
  return 0;
}

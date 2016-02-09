// kadalbonek
#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int a[N];

int main() {
  int n;
  scanf("%d", &n);
  int m = 2 * (n - 1);
  int sum = 0;
  vector<pair<int, int>> vec;
  
  for(int i = 1; i <= n; i++) {
    scanf("%d", a + i);
    vec.emplace_back(a[i], i);
    sum += a[i];
    if(a[i] == 0) {
      puts("-1");
      return 0;
    }
  }
  if(sum != m) {
    puts("-1");
    return 0;
  }
  sort(vec.begin(), vec.end());
  reverse(vec.begin(), vec.end());
  int j = 1;
  for(int i = 0; i < vec.size(); i++) {
    while(a[vec[i].second] != 0) {
      printf("%d %d\n", vec[i].second, vec[j].second);
      a[vec[i].second]--;
      a[vec[j].second]--;
      j++;
    }
  }
  return 0;
}
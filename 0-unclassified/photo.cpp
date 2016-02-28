#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

pair<int, int> ada[N];

int main() {
  int n, d, a, b;
  scanf("%d %d", &n, &d);
  scanf("%d %d", &a, &b);
  for(int i = 1; i <= n; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    ada[i] = make_pair(x * a + y * b, i);
  }
  sort(ada + 1, ada + 1 + n);
  int ans = n;
  long long now = 0;
  for(int i = 1; i <= n; i++) {
    if(now + ada[i].first <= d) {
      now += ada[i].first;
    } else {
      ans = i - 1;
      break;
    }
  }
  cout << ans << endl;
  for(int i = 1; i <= ans; i++) {
    printf("%d ", ada[i].second);
  }
  printf("\n");
  return 0;
}
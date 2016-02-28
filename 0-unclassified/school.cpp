#include <bits/stdc++.h>

using namespace std;

int n, k, p, x, y;
vector<int> a;
vector<int> ans;

int main() {
  scanf("%d %d %d %d %d", &n, &k, &p, &x, &y);
  int up = n / 2 + 1;
  int sum = 0;
  for(int i = 0; i < k; i++) {
    int num;
    scanf("%d", &num);
    a.push_back(num);
    if(y <= num && up) {
      up--;
    }
    sum += num;
  }
  if(up && p < y || n - k < up) {
    puts("-1");
    return 0;
  }
  sum += up * min(p, y) + max(0, (n - k - up));
  int limit = x;
  if(sum <= limit) {
    for(int i = 0; i < up; i++) {
      printf("%d ", y);
    }
    for(int i = 0; i < max(0, (n - k - up)); i++) {
      printf("1 ");
    }
    printf("\n");
  } else {
    puts("-1");
  }
  return 0;
}

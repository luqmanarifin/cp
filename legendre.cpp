#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int odd[] = {0, 1, 0, 1, 2, 0};
int even[] = {0, 1, 2};

int find_odd(int num) {
  if(num <= 5) return odd[num];
  if(num % 2) return 0;
  int b = find_odd(num / 2);
  if(b == 0) {
    return 1;
  } else if(b == 1) {
    return 2;
  } else {
    return 1;
  }
}

int find_even(int num) {
  if(num <= 2) return even[num];
  if(num % 2) return 0;
  return 1;
}

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  int ans = 0;
  for(int i = 0; i < n; i++) {
    int val;
    scanf("%d", &val);
    if(k % 2) {
      ans ^= find_odd(val);
    } else {
      ans ^= find_even(val);
    }
  }
  puts(ans? "Kevin" : "Nicky");
  return 0;
}

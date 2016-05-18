#include <bits/stdc++.h>

using namespace std;

const long long inf = 1e18;
const double eps = 1e-13;

int main() {
  int m, n, t;
  scanf("%d %d %d", &m, &n, &t);
  long long ans;
  if(t == 1) {
    ans = 1;
    for(int i = 2; i <= n; i++) {
      ans *= i;
      if(ans > m) break;
    }
  } else if(t == 2) {
    ans = 1;
    for(int i = 0; i < n; i++) {
      ans *= 2;
      if(ans > m) {
        break;
      }
    }
  } else if(t == 3) {
    ans = 1;
    for(int i = 0; i < 4; i++) {
      ans *= n;
      if(ans > m) break;
    }
  } else if(t == 4) {
    ans = 1;
    for(int i = 0; i < 3; i++) {
      ans *= n;
      if(ans > m) break;
    }
  } else if(t == 5) {
    ans = 1;
    for(int i = 0; i < 2; i++) {
      ans *= n;
      if(ans > m) break;
    }
  } else if(t == 6) {
    double temp = n;
    for(int i = 0; i < 1; i++) {
      temp *= log(n) / log(2);
      if(temp > m) break;
    }
    //printf("%.15f\n", temp);
    puts(temp - eps < m? "AC" : "TLE");
    return 0;
  } else {
    ans = n;
  }
  puts(ans <= m? "AC" : "TLE");
  return 0;
}


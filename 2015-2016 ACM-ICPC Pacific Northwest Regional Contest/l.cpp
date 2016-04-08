#include <bits/stdc++.h>

using namespace std;

char s[10];

int main() {
  int n, w;
  scanf("%d %d", &n, &w);
  int safe = 0, prize = 0;
  double ans = 0, prob = 1, now = 0;
  while(n--) {
    double p;
    int v;
    scanf("%s %lf %d", s, &p, &v);
    prize = v;
    double win =  prob * p * log(1 + (double)prize/w);
    double lose = prob * (1 - p) * log(1 + (double)safe/w);
    ans = max(ans, now + win + lose);
    now += lose;
    prob *= p;
    if(s[0] == 's') {
      safe = prize;
    }
  }
  printf("$%.2f\n", w * (exp(ans) - 1));
  return 0;
}
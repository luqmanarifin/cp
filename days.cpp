#include <bits/stdc++.h>

using namespace std;

int day[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int week[] = {52, 52, 52, 52, 53, 53, 52};

char a[25], s[25];

int main() {
  int n;
  scanf("%d", &n);
  scanf("%s %s", a, s);
  if(s[0] == 'w') {
    n--;
    printf("%d\n", week[n]);
  } else {
    int ans = 0;
    for(int i = 0; i < 12; i++) {
      if(day[i] >= n) {
        ans++;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}

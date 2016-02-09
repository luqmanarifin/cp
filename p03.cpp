#include <bits/stdc++.h>

using namespace std;

const int N = 55;

int score[N];
char s[N][N];

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%s", s[i]);
    for(int j = 0; j < n; j++) {
      if(s[i][j] == 'W') {
        score[i] += 3;
      } else if(s[i][j] == 'L') {
        score[j] += 3;
      } else if(s[i][j] == 'D') {
        score[i]++;
        score[j]++;
      }
    }
  }
  for(int i = 0; i < n; i++) {
    if(i > 0) printf(" ");
    printf("%d", score[i]);
  }
  printf("\n");
  return 0;
}

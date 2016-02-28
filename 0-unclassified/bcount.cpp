#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int ada[N][5];

int main() {
  freopen("bcount.in","r",stdin);
  freopen("bcount.out","w",stdout);
  int n, q;
  scanf("%d %d", &n, &q);
  for(int i = 1; i <= n; i++) {
    int a;
    scanf("%d", &a);
    ada[i][a] = 1;
    for(int j = 1; j <= 3; j++) {
      ada[i][j] += ada[i - 1][j];
    }
  }
  while(q--) {
    int l, r;
    scanf("%d %d", &l, &r);
    printf("%d %d %d\n", ada[r][1] - ada[l - 1][1], ada[r][2] - ada[l - 1][2], ada[r][3] - ada[l - 1][3]);
  }
  fclose(stdin);
  fclose(stdout);
  return 0;
}

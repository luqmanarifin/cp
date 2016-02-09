#include <bits/stdc++.h>

using namespace std;

const int N = 55;

int num[N], den[N];
char s[N];

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%s", s);
    den[i] = strlen(s);
    for(int j = 0; j < den[i]; j++) {
      if(s[j] == '1') {
        num[i]++;
      }
    }
  }
  int p = 0;
  for(int i = 1; i < n; i++) {
    if(num[i] * den[p] < num[p] * den[i]) {
      p = i;
    }
  }
  cout << p << endl;
  return 0;
}

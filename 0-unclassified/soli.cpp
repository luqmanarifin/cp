#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N];
int l[N], r[N];

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 1; i <= n; i++) {
    scanf("%d", a + i);
    a[i] %= 2;
  }
  for(int i = 0; i <= n + 1; i++) {
    l[i] = i - 1;
    r[i] = i + 1;
  }
  for(int i = 1; i <= n; i = r[i]) {
    //printf("%d ", i);
    if(a[i] == a[l[i]] && l[i] > 0) {
      int ll = l[l[i]];
      int rr = r[i];
      r[ll] = rr;
      l[rr] = ll;
    }
  }
  vector<int> num;
  for(int i = r[0]; i <= n; ) {
    num.push_back(a[i]);
    i = r[i];
  }
  /*
  int i = 0, j = (int) num.size() - 1;
  while(i < j) {
    if(num[i] == num[j]) {
      i++;
      j--;
    } else {
      break;
    }
  }
  */
  printf("%d\n", num.size());
  return 0;
}

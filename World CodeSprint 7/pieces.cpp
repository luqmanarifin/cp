#include <bits/stdc++.h>

using namespace std;

long long mod = 1e9 + 7;

int main() {
  int n;
  scanf("%d", &n);
  long long sumi = 0;
  long long sum = 0;
  long long sumd = 0;
  long long dua = 1;
  long long diag = 0;
  long long triangle = 0;
  long long ans = 0;
  long long all = 0;
  long long first;
  long long carry = 0;
  for (int i = 0; i < n; i++) {
    if (i >= 2) dua *= 2;
    int a;
    scanf("%d", &a);
    if (i == 0) first = a;
    sumi += i;
    triangle -= diag;
    if (i) triangle += triangle - (sum - first) * i;
    sum += a;
    triangle += sum * (i + 1);
    carry = carry * 2 + i;
    triangle += 1LL * a * carry;
    sumd += dua * a;
    diag += sumd;
    ans = all + triangle;
    all += ans;
    cout << ans << endl;
  }
  cout << ans << endl;
  return 0;
}
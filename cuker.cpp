#include <bits/stdc++.h>

using namespace std;
char s[100003];
long long ans = 0;
int i = 0;

long long solve(int l) {
  long long sums = 0L, combined = 0L;
  int stack = 0;
  while(true)
  if (s[i + 1] == '(')  {
    long long tmp = solve(++i);
    combined += tmp * sums;
    sums += tmp;
  } else {
    ans += combined * (i + 2 - l);
    //printf("%I64d %I64d\n",sums,combined);
    i++;
    return sums + 1;
  }
}


int main() {
  gets(s);
  solve(i);
  printf("%I64d\n",ans);
}
#include <bits/stdc++.h>

using namespace std;

long long l, r;
long long ten[20];

int digit(long long a) {
  int temp = 1;
  a /= 10;
  while(a) {
    temp++;
    a /= 10;
  }
  return temp;
}

long long solve(long long a) {
  if(a < 10) {
    return a;
  }
  long long ret = 0;
  int dig = digit(a);
  for(int i = 1; i < dig; i++) {
    ret += 9 * ten[max(0, i - 2)];
  }
  long long pol = a / ten[dig - 1];
  long long rig = a % 10;
  if(dig == 2) {
    if(pol > rig) ret += pol - 1;
    else ret += pol;
    //cout << ret << endl;
    return ret;
  }
  ret += (pol - 1) * ten[max(0, dig - 2)];
  a -= pol * ten[dig - 1];
  a /= 10;
  if(pol <= rig) {
    a++;
  }
  ret += a;
  //cout << ret << endl;
  return ret;
}

int main() {
  ten[0] = 1;
  for(int i = 1; i < 20; i++) {
    ten[i] = ten[i - 1] * 10;
  }
  scanf("%I64d %I64d", &l, &r);
  cout << solve(r) - solve(l - 1) << endl;
  return 0;
}
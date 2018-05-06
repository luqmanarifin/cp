
#include <bits/stdc++.h>

using namespace std;

template <typename t>
t getnum()
{
  t res=0, mult=1;
  char c;
  while(1) {
    c=getchar(); if(c==' ' || c=='\n') continue; else break;
  }
  if(c=='-') mult*=-1; else res+=c-'0';
  while(1) {
    c=getchar();
    if(c>='0' && c<='9') { res*=10; res+=c-'0'; }
    else break;
  }
  return res*mult;
} 

int main() {
  long long a = getnum<long long>();
  cout << a << endl;

  return 0;
}

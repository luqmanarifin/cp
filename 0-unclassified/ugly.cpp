// too easy to AC
#include <bits/stdc++.h>

using namespace std;

long long sm, bg;
long long a, l, r;

void validate(long long ans) {
  assert(l <= ans && ans <= r);
}

int main() {
  cin >> a >> l >> r;
  bool dif = 0;
  bool freebig = 0, freesmall = 0;
  long long all = 0;
  for(int i = 62; i >= 0; i--) {
    if((l & (1LL << i)) != (r & (1LL << i))) {
      dif = 1;
    }
    if(!dif) {
      sm |= (l & (1LL << i)) ^ (a & (1LL << i));
      bg |= (l & (1LL << i)) ^ (a & (1LL << i));
    } else {
      if(freebig) {
        if((bg & all) == (l & all) && (a & (1LL << i)) && (a & (1LL << i)) == (l & (1LL << i))) {
          
        } else {
          bg |= (1LL << i);
        }
      } else {
        if((r & (1LL << i)) == (a & (1LL << i))) {
          if((r & (1LL << i))) {
            freebig = 1;
            bg |= (1LL << i);
          } else {
            
          }
        } else {
          bg |= (1LL << i);
        }
      }
      if(freesmall) {
        if((sm & all) == (r & all) && (a & (1LL << i)) > (r & (1LL << i))) {
          sm |= (1LL << i);
        }
      } else {
        if((l & (1LL << i)) != (a & (1LL << i))) {
          if((a & (1LL << i))) {
            freesmall = 1;
          } else {
            sm |= (1LL << i);
          }
        } else {

        }
      }
    }
    all |= (1LL << i);
  }
  validate(sm ^ a);
  validate(bg ^ a);
  cout << sm << ' ' << bg << endl;
  return 0;
}

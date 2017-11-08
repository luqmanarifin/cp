#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
#define fi first
#define se second
const int N = 35;

pii ar[N];

int main() {
  
  int n;
  scanf("%d", &n);
  int tot = 0;
  int maks = 0;
  for(int i = 0;i < n; ++i) {
    int x;
    cin >> x;
    tot += x;
    maks = max(maks, x);
    ar[i] = {x, i};
  }
  if(maks * 2 > tot){
    puts("impossible");
  }
  else{
    sort(ar,ar + n);
    for(int i = n - 1;i >= 0; --i) printf("%d%c", ar[i].se + 1, i == 0 ? '\n' : ' ');
  }
  return 0;
}

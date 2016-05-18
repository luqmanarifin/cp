#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;

int da[] = {1, 1, -1, -1};
int db[] = {-1, 1, -1, 1};

int a[N], b[N];

int p[N];                         // id node terdekat
vector<pair<int, int>> sw[4];     // line sweep

char s[2005][2005], junk[20];

int main() {
  int n, m, k, q;
  scanf("%s %d %d %d %d", junk, &n, &m, &k, &q);
  int aw = 0;
  for(int i = 1; i <= n; i++) {
    scanf("%s", s[i] + 1);
    for(int j = 1; j <= k; j++) {
      if(s[i][j] == 'X') {
        ++aw;
        a[aw] = i;
        b[aw] = j;
        
      }
    }
  }
  assert(aw == k);
  
  return 0;
}

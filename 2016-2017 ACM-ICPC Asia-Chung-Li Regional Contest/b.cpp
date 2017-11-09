#include <bits/stdc++.h>

using namespace std;
const int N = 5e3;
pair<int,int> ar[N + 5];
#define fi first
#define se second

long long sqr(long long a){
  return a * a;
}
long long dist(int i, int j){
  return sqr(ar[i].fi - ar[j].fi) + sqr(ar[i].se - ar[j].se); 
}

int main() {
  
  int t;
  scanf("%d", &t);
  while(t--){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) scanf("%d%d", &ar[i].fi, &ar[i].se);
    long long min_dist = dist(0, 1);
    for(int i = 0; i < n; ++i){
      for(int j = i + 1;j < n; ++j){
        min_dist = min(min_dist, dist(i, j));
      }
    }
    double real_dist = sqrt(min_dist);
    printf("%.2lf\n", real_dist);
  }
  return 0;
}

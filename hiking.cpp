#include <bits/stdc++.h>

using namespace std;

const double eps = 1e-14;
const double inf = 1e15;

double cost[1005][1005];
double dist[1005];
int bef[1005];
int x[1005];
int b[1005];
int l, n;

double equal(double a, double c) {
  return abs(a - c) < eps;
}

bool is_kurang(double r) {
  for(int i = 0; i <= n; i++) {
    for(int j = i + 1; j <= n; j++) {
      cost[i][j] = sqrt(abs(x[j] - x[i] - l)) - r * b[j];
    }
  }
  for(int i = 0; i <= n; i++) {
    dist[i] = inf;
  }
  dist[0] = 0;
  for(int i = 0; i <= n; i++) {
    for(int j = i + 1; j <= n; j++) {
      if(dist[i] + cost[i][j] < dist[j]) {
        dist[j] = dist[i] + cost[i][j];
        bef[j] = i;
      }
    }
  }
  return dist[n] > 0;
}

void print(int a) {
  if(a == 0) {
    return;
  }
  print(bef[a]);
  printf("%d ", a);
}

int main() {
  scanf("%d %d", &n, &l);
  for(int i = 1; i <= n; i++) {
    scanf("%d %d", x + i, b + i);
  }
  double lef = 0.0, rig = 10000.0;
  for(int tt = 0; tt < 75; tt++) {
    double mid = (lef + rig) / 2;
    //printf("%.15lf %.15lf %.15lf %d\n", lef, mid, rig, tt);
    if(is_kurang(mid)) lef = mid;
    else rig = mid;
  }
  print(n); printf("\n");
  return 0;
}
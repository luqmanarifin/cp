#include <bits/stdc++.h>
 
using namespace std;
 
const long double eps = 1e-13;
const int iter_arc = 75;
const int iter_rad = 75;
const int iter_cnt = 5000;
 
long double lmin(long double a, long double b) {
  return (a < b? a : b);
}
 
bool equal(long double a, long double b) {
  return abs(a - b) < eps;
}
 
#define phi acos(-1.0)
 
long double toDeg(long double a) {
  return a * 180 / phi;
}
 
vector<int> num;
long double rad[5], arc[5];
int cnt[5];
long double x2, y2;
 
long double dist(long double a, long double b, long double c, long double d) {
  return sqrt((a - c)  * (a - c) + (b - d) * (b - d));
}

bool assignleft() {
  for(int i = 3; i <= 4; i++) {
    long double j = rad[1] - rad[i];
    long double x = (rad[1] - rad[i - 1]) * cos(arc[i - 1]);
    long double y = (rad[1] - rad[i - 1]) * sin(arc[i - 1]);
    
    long double l = arc[i - 1];
    long double r = lmin(2 * phi, arc[i - 1] + phi);
    for(int it = 0; it < iter_arc; it++) {
      long double mid = (l + r) / 2;
      if(dist(j * cos(mid), j * sin(mid), x, y) < rad[i-1] + rad[i]) {
        l = mid;
      } else {
        r = mid;
      }
    }
    arc[i] = l;
    if(!equal(dist(j * cos(r), j * sin(r), x2, y2), rad[2] + rad[i])) {
      return 0;
    }
  }
  return 1;
} 

void assignright() {
  {
    int i = 3;
    long double j = rad[1] - rad[i];
    long double x = (rad[1] - rad[i - 1]) * cos(arc[i - 1]);
    long double y = (rad[1] - rad[i - 1]) * sin(arc[i - 1]);
    
    long double l = phi;
    long double r = 2 * phi;
    for(int it = 0; it < iter_arc; it++) {
      long double mid = (l + r) / 2;
      if(dist(j * cos(mid), j * sin(mid), x, y) < rad[i-1] + rad[i]) {
        r = mid;
      } else {
        l = mid;
      }
    }
    arc[i] = l;
  }
  {
    int i = 4;
    long double j = rad[1] - rad[i];
    long double x = (rad[1] - rad[i - 1]) * cos(arc[i - 1]);
    long double y = (rad[1] - rad[i - 1]) * sin(arc[i - 1]);
    
    long double l = arc[i - 1];
    long double r = lmin(2 * phi, arc[i - 1] + phi);
    for(int it = 0; it < iter_arc; it++) {
      long double mid = (l + r) / 2;
      if(dist(j * cos(mid), j * sin(mid), x, y) < rad[i-1] + rad[i]) {
        l = mid;
      } else {
        r = mid;
      }
    }
    arc[i] = l;
  }
}

int main() {
  int t, n, p, m, b;
  scanf("%d %d %d %d %d", &t, &n, &p, &m, &b);
  for(int i = 1; i <= 4; i++) {
    double tmp;
    scanf("%lf", &tmp);
    rad[i] = (long double) tmp;
  }
  for(int i = 1; i <= t; i++) {
    n = (1LL * p * n) % m + b;
    if(n <= 4) {
      cnt[n]++;
    } else {
      num.push_back(n);
    }
  }
  for(int i = 6; i <= 10; i++) {
    num.push_back(i);
  }
  sort(num.begin(), num.end());
  x2 = rad[1] - rad[2];
  y2 = 0;
  if(!assignleft()) {
    assignright();
  }
  
  long double ans = 0;
  for(int i = 1; i <= 4; i++) {
    ans += cnt[i] * rad[i];
    //printf("%d %lf\n", i, (double) toDeg(arc[i]));
  }
  
  long double bef = arc[4];
  long double j = rad[4];
  int id = 4;
  int i = 0;
  for(int iter = 0; iter < iter_cnt && i < num.size(); iter++) {
    ++id;
    long double x = (rad[1] - j) * cos(bef);
    long double y = (rad[1] - j) * sin(bef);
    long double la = bef;
    long double ra = lmin(2 * phi, bef + phi);
    long double now;
    for(int it = 0; it < iter_arc; it++) {
      long double mida = (la + ra) / 2;
      
      long double lj = 0;
      long double rj = j;
      for(int jt = 0; jt < iter_rad; jt++) {
        long double midj = (lj + rj) / 2;
        long double c = rad[1] - midj;
        long double distbef = dist(c * cos(mida), c * sin(mida), x, y) - j;
        if(midj < distbef) {
          lj = midj;
        } else {
          rj = midj;
        }
      }
      
      now = (lj + rj) / 2;
      long double midj = (lj + rj) / 2;
      long double c = rad[1] - midj;
      long double dist2 = dist(c * cos(mida), c * sin(mida), x2, y2) - rad[2];
      long double distbef = dist(c * cos(mida), c * sin(mida), x, y) - j;
      if(distbef < dist2) {
        la = mida;
      } else {
        ra = mida;
      }
    }
    bef = (la + ra) / 2;
    j = now;
    printf("%d %.16lf\n", id, (double) j);
    while(i < num.size() && num[i] == id) {
      ans += j;
      i++;
    }
  }
  printf("%.6lf\n", (double) ans);
  return 0;
}
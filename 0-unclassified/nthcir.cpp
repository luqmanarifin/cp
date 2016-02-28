#include <bits/stdc++.h>
 
using namespace std;

// 100 * 1 juta TLE
// 100 * 500 rb TLE
// 100 * 100 rb TLE
// 100 * 10 rb nge-press dan  WA

const long double eps = 1e-10;
const int iter_arc = 100;
const int iter_cnt = 10000;
 
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
  
  int i = 0, id = 4;
  long double c = rad[4];
  long double ab = arc[4];
  for(int it = 0; it < iter_cnt && i < num.size(); it++) {
    ++id;
    long double x = (rad[1] - c) * cos(ab);
    long double y = (rad[1] - c) * sin(ab);
    
    long double l = ab;
    long double r = 2 * phi;
    for(int jt = 0; jt < iter_arc; jt++) {
      long double mid = (l + r) / 2;
      long double xx = cos(2 * phi - mid) * (rad[1] - rad[2]) - cos(mid - ab) * (rad[1] - c);
      long double d = (-c + rad[2] + xx) * rad[1] / (c - rad[2] + xx);
      long double x_cor = (rad[1] - d) * cos(mid);
      long double y_cor = (rad[1] - d) * sin(mid);
      if(dist(x_cor, y_cor, x2, y2) - rad[2] < dist(x_cor, y_cor, x, y) - c) {
        r = mid;
      } else {
        l = mid;
      }
    }
    long double mid = (l + r) / 2;
    long double xx = cos(2 * phi - mid) * (rad[1] - rad[2]) - cos(mid - ab) * (rad[1] - c);
    c = (-c + rad[2] + xx) * rad[1] / (c - rad[2] + xx);
    ab = mid;
    //printf("%d %.16lf\n", id, (double) c);
    while(i < num.size() && num[i] == id) {
      ans += c;
      i++;
    }
  }
  printf("%.6lf\n", (double) ans);
  return 0;
}
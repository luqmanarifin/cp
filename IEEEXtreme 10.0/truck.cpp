#include <bits/stdc++.h>

using namespace std;

const double r = 6378.137;
const double PI = acos(-1.0);

struct Date {
  Date(int a, int b, int c, int d, int e) {
    MM = a;
    DD = b;
    YYYY = c;
    hh = d;
    mm = e;
  }
  int MM, DD, YYYY;
  int hh, mm;
  bool operator <(Date other) const {
    if (YYYY < other.YYYY) return 1;
    if (YYYY > other.YYYY) return 0;
    if (MM < other.MM) return 1;
    if (MM > other.MM) return 0;
    if (DD < other.DD) return 1;
    if (DD > other.DD) return 0;
    if (hh < other.hh) return 1;
    if (mm < other.mm) return 0;
    return 0;
  }
  bool operator==(Date other) const {
    return MM == other.MM && DD == other.DD && YYYY == other.DD && hh == other.hh && mm == other.mm;
  }
};

double toRad(double degree) {
  return degree * PI / 180;
}

double LAT, LONG;
char s[1005];
map<string, pair<double, Date>> MP;

double dist(double lat1, double long1, double lat2, double long2) {
  double a = sin((lat1 - lat2)/2)*sin((lat1 - lat2)/2) + cos(lat1) * cos(lat2) * sin((long1 - long2)/2)*sin((long1 - long2)/2);
  if (a < 0) a = 0;
  a = sqrt(a);
  if (a > 1) a = 1;
  if (a < -1) a = -1;
  a = asin(a);
  return 2 * r * a;
}

int main() {
  double R, lat, longg;
  scanf("%lf %lf %lf %s", &LAT, &LONG, &R, s);
  LAT = toRad(LAT);
  LONG = roRad(LONG);
  int m, d, y, hh, mm;
  while (scanf("%d/%d/%d %d:%d,%lf,%lf,%s", &m, &d, &y, &hh, &mm, &lat, &longg, s) == 8) {
    lat = toRad(LAT);
    longg = toRad(longg);
    if ()
  }
  
  return 0;
}

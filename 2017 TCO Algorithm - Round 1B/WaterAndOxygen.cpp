#include <bits/stdc++.h>

using namespace std;

class WaterAndOxygen {
public:
  double water, air;
  double water_day, air_day;
  double solve(double t) {
    double w = water - t;
    double a = air + t / 2;
    return min(w / water_day, a / air_day);
  }

  double maxDays(int w, int a, int c, int d) {
    water = w;
    air = a;
    water_day = c;
    air_day = d;
    double l = 0, r = w;
    for (int it = 0; it < 200; it++) {
      double lf = l + (r - l) / 3;
      double rf = r - (r - l) / 3;
      if (solve(lf) > solve(rf)) {
        r = rf;
      } else {
        l = lf;
      }
    }
    return solve(r);
  }
};
/*
int main() {
  int l = 0;
  int r = 0;
  
  WaterAndOxygen WaterAndOxygen;
  cout << WaterAndOxygen.maxDays() << endl;
  
  return 0;
}
*/
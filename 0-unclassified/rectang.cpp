#include <bits/stdc++.h>

using namespace std;

long long find_genap(long long a, long long b) {
  if(a % 2) a++;
  if(b % 2) b--;
  if(a > b) return 0;
  return (b - a) / 2 + 1;
}

long long find_ganjil(long long a, long long b) {
  if(a % 2 == 0) a++;
  if(b % 2 == 0) b--;
  if(a > b) return 0;
  return (b - a) / 2 + 1;
}

int main() {
  long long a, b, c, d;
  cin >> a >> b >> c >> d;
  long long ans = find_ganjil(a, c) * find_ganjil(b, d) + find_genap(a, c) * find_genap(b, d);
  ans = max(ans, find_ganjil(a, c) * find_genap(b, d) + find_genap(a, c) * find_ganjil(b, d));
  cout << ans << endl;
  return 0;
}
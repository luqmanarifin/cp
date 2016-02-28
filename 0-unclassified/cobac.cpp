#include <bits/stdc++.h>

using namespace std;

#define int long long

int gcd( int a, int b) {
	int remainder;
	while (b != 0) {
		remainder = a % b;
		a = b;
		b = remainder;
	}
	return a;
}

int get(int number) {
	int x_fixed = 2, cycle_size = 2, x = 2, factor = 1;
 
	while (factor == 1) {
 
		for (int count=1;count <= cycle_size && factor == 1;count++) {
			x = (x*x+1)%number;
			factor = gcd(abs(x - x_fixed), number);
      //cout << x - x_fixed << ' ' << number << endl;
		}
 
		cycle_size *= 2;
		x_fixed = x;
	}
	return factor;
}

main () {
  long long n = 1000000000000000000LL;
  cout << n << ' ' << get(n) << endl;

  return 0;
}
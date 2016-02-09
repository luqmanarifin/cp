#include <bits/stdc++.h>

typedef long long LL;
typedef double DB;

#define sf scanf
#define pf printf
#define mp make_pair
#define nl printf("\n")

#define FOR(i,a,b) for(i = a; i <= b; ++i)
#define FORD(i,a,b) for(i = a; i >= b; --i)
#define FORS(i,n) for(i = 0; i < n; ++i)
#define FORM(i,n) for(i = n - 1; i >= 0; --i)
#define reset(i,n) memset(i, n, sizeof(i))

using namespace std;

const LL mod = 1e9 + 7;
const LL INF = 4e18;
const int inf = 2e9;
const double eps = 1e-13;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

#define SIZE 3

int t[SIZE][SIZE];
int a[SIZE];
int temp[SIZE][SIZE];

void multiply_temp_temp() {
	int ret[SIZE][SIZE];
	for(int i = 0; i < SIZE; i++)
		for(int j = 0; j < SIZE; j++) {
			ret[i][j] = 0;
			for(int k = 0; k < SIZE; k++) {
				ret[i][j] += temp[i][k] * temp[k][j];
			}
		}
	for(int i = 0; i < SIZE; i++)
		for(int j = 0; j < SIZE; j++) {
			temp[i][j] = ret[i][j];
		}
}

void multiply_t_with_temp() {
	int ret[SIZE][SIZE];
	for(int i = 0; i < SIZE; i++)
		for(int j = 0; j < SIZE; j++) {
			ret[i][j] = 0;
			for(int k = 0; k < SIZE; k++) {
				ret[i][j] += t[i][k] * temp[k][j];
			}
		}
	for(int i = 0; i < SIZE; i++)
		for(int j = 0; j < SIZE; j++) {
			temp[i][j] = ret[i][j];
		}
}

void multiply_a_with_t_power() {
	int ret[SIZE];
	for(int j = 0; j < SIZE; j++) {
		ret[j] = 0;
		for(int k = 0; k < SIZE; k++) {
			ret[j] += a[k] * temp[k][j];
		}
	}
	for(int j = 0; j < SIZE; j++) {
		a[j] = ret[j];
	}
}

void power_t(LL n) {
	if(n == 0) return;
	power_t(n/2);
	multiply_temp_temp();
	if(n % 2) {
		multiply_t_with_temp();
	}
}

int main(void)
{
	clock_t tt = clock();
	t[0][0] = 0; t[0][1] = 0; t[0][2] = 2;
	t[1][0] = 1; t[1][1] = 0; t[1][2] = 2;
	t[2][0] = 0; t[2][1] = 1; t[2][2] = 1;
	
	a[0] = 1; a[1] = 3; a[2] = 5;
	
	temp[0][0] = 1; temp[0][1] = 0; temp[0][2] = 0;
	temp[1][0] = 0; temp[1][1] = 1; temp[1][2] = 0;
	temp[2][0] = 0; temp[2][1] = 0; temp[2][2] = 1;
	
	LL n = 1e18;
	power_t(n - 1);
	multiply_a_with_t_power();
	cout << a[0] << endl;
	tt = clock() - tt;
	printf ("It took me (%.3lf miliseconds).\n", ((double)tt*1000)/CLOCKS_PER_SEC);
	return 0;
}

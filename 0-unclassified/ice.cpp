#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include <climits>
#include <vector>
#include <map>
#include <list>
#include <deque>
#include <stack>
#include <set>
#include <string>
#include <cstring>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <utility>
#include <functional>

using namespace std;

#define LL long long
#define PI acos(-1.0)
#define sf scanf
#define pf printf
#define nl printf("\n")
#define FOR(i,a,b) for( i=a; i<=b; i++)
#define FORD(i,a,b) for( i=b; i>=a; i--)
#define FORS(i,n) FOR(i, 0, n-1)
#define FORM(i,n) FORD(i, 0, n-1)
#define mp make_pair
#define open freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
#define close fclose(stdin); fclose(stdout)
#define db double

const int N = 1000010;

int gcd(int a, int b) { return b? gcd(b,a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a,b); }

int main(void)
{
	int n, t[20010], i, j, k;
	signed LL ans = 0, temp;
	sf("%d", &n);
	FORS(i,n) {
		sf("%d", &t[i]);
		ans += t[i];
	}
	FOR(i,2,n/3) {
		if(n%i == 0) {
			FORS(j,i) {
				temp = 0;
				for(k = j; k < n; k += i)
					temp += t[k];
				ans = max(temp, ans);
			}
		}
	}
	cout << ans << endl;
	
	return 0;
}
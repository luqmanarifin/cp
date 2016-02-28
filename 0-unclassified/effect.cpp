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
#define FORM(i,a,b) for( i=b; i>=a; i--)
#define FORS(i,n) FOR(i, 0, n-1)
#define FORD(i,n) FORM(i, 0, n-1)
#define mp make_pair
#define open freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
#define close fclose(stdin); fclose(stdout)
#define db (double)

const int N = 1000010;

int gcd(int a, int b) { if(!b) return a; return gcd(b,a%b); }
int lcm(int a, int b) { return a*b / gcd(a,b); }

bool kanan[3010], kiri[3010];
char a[3010];
int n, i, j, ans = 0;;

int main()
{
	sf("%d", &n);
	memset(kanan, 0, sizeof(kanan));
	memset(kiri, 0, sizeof(kiri));
	cin >> a;
	i = 0;
	while(i < n) {
		if(a[i] == 'R') {
			kanan[i]++;
			j = i+1;
			while(a[j] == '.' && i < n) {
				kanan[j]++;
				j++;
			}	
		}
		i = max(i,j);
		i++;
	}
	i = n-1; j = n-1;
	while(i >= 0) {
		if(a[i] == 'L') {
			kiri[i]++;
			j = i-1;
			while(a[j] == '.' && i >= 0) {
				kiri[j]++;
				j--;
			}	
		}
		i = min(i,j);
		i--;
	}
	int streak = 0;
	FORS(i,n) {
		if(!kanan[i] && !kiri[i]) {
			ans++;
			streak = 0;
		}
		else if(kanan[i] && kiri[i])
			streak++;
		else if(streak%2) {
			ans++;
			streak = 0;
		}
		else streak = 0;
	}
	//FORS(i,n) pf("%d", kanan[i]); nl;
	//FORS(i,n) pf("%d", kiri[i]); nl;
	cout << ans << endl;
	return 0;
}
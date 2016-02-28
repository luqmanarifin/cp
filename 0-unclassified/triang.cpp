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

int gcd(int a, int b) { if(!b) return a; return gcd(b,a%b); }
int lcm(int a, int b) { return a*b / gcd(a,b); }

int main(void)
{
	int a, b, i, j, k, l;
	sf("%d %d", &a, &b);
	if(a > b) swap(a,b);
	FOR(i,1,a-1) {
		FOR(j,1,a-1) {
			if((LL)i*i + j*j == (LL)a*a) {
				FOR(k,1,b-1) {
					FOR(l,1,b-1) {
						if((LL)k*k + l*l == (LL)b*b) {
							if(i != k && (i-k)*(i-k)+(j+l)*(j+l) == a*a+b*b) {
								puts("YES");
								pf("0 0\n%d %d\n%d %d\n",-j,i,l,k);
								return 0;
							}
						}
					}
				}
			}
		}
	}
	puts("NO");
	
	return 0;
}
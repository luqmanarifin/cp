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

int gcd(int a, int b) { return b? gcd(b,a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a,b); }

int main(void)
{
	int k, n, m, x, i, j, l, mask;
	sf("%d %d %d %d", &k, &x, &n, &m);
	FOR(i,0,n/2) {
		FOR(j,0,m/2) {
			FORS(mask,16) {
				int a = mask&1, b = (mask>>1)&1, c = (mask>>2)&1, d = (mask>>3)&1;
				LL first = i, second = j, temp;
				if(a+b+i*2 > n || c+d+j*2 > m) continue;
				int A = a, B = b, C = c, D = d;
				FOR(l,3,k) {
					temp = first + second + (B && C);
					B = D;
					swap(A, C);
					first = second;
					second = temp;
				}
				if(second == x) {
					if(a) putchar('C');
					FORS(l,i) pf("AC");
					FORS(l,n-2*i-a-b) putchar('X');
					if(b) putchar('A'); nl;
					
					if(c) putchar('C');
					FORS(l,j) pf("AC");
					FORS(l,m-2*j-c-d) putchar('X');
					if(d) putchar('A'); nl;
					
					return 0;
				}
			}
		}
	}

	puts("Happy new year!");	
	
	return 0;
}
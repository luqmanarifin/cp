#include <bits/stdc++.h>

using namespace std;

#define LL long long
#define DB double
#define sf scanf
#define pf printf
#define nl printf("\n")
#define FOR(i,a,b) for(i = a; i <= b; ++i)
#define FORD(i,a,b) for(i = a; i >= b; --i)
#define FORS(i,n) for(i = 0; i < n; ++i)
#define FORM(i,n) for(i = n - 1; i >= 0; --i)
#define reset(i,n) memset(i, n, sizeof(i))
#define open freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
#define close fclose(stdin); fclose(stdout)
#define mp make_pair

const LL mod = 1e9 + 7;
const LL inf = 4e18;
const int b = 1000;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a, b); }

int car[2100][1005];

int main(void)
{
	//open;
	int n, i, j, sum = 0;
	int len = 0, now = b;
	int mini = b, maxi = b;
	sf("%d", &n);
	FOR(i,1,n) {
		int x;
		sf("%d", &x);
		sum += x;
		len++;
		if(i&1) car[now][len] = 1;
		else car[now][len] = -1;
		
		FORS(j,x-1) {
			len++;
			if(i&1) {
				now++;
				car[now][len] = 1;
			} else {
				now--;
				car[now][len] = -1;
			}
		}
		if(now > maxi) maxi = now;
		else if(now < mini) mini = now;
	}
	
	FORD(i,maxi, mini) {
		FOR(j,1,sum) {
			if(car[i][j] == 1) pf("/");
			else if(car[i][j] == -1) putchar((char)92);
			else pf(" ");
		}
		nl;
	}
	//close;
	return 0;
}

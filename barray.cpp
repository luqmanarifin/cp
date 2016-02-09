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
#define open freopen("input.txt","r",stdin); freopen("aa.txt","w",stdout)
#define close fclose(stdin); fclose(stdout)
#define mp make_pair

const LL mod = 1e9 + 7;
const int N = 1e6;
const int N2 = 2*N + 5;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a, b); }

int sum[N2];

int main(void)
{
	//open;
	clock_t t;
	int n, k; sf("%d %d", &n, &k);
	t = clock();
	int minAnswer = N, i, j;
	FORS(i,n) {
		int x;
		sf("%d", &x);
		sum[x]++;
		if(x < minAnswer)
			minAnswer = x;
	}
	FOR(i,1,N2-1) sum[i] += sum[i-1];

	if(minAnswer <= k) { cout << minAnswer << endl; return 0; }
	
	FORD(i,minAnswer,1) {
		int num = 0;
		for(j = i; j <= N; j += i) {
			num += sum[j + k] - sum[j - 1];
			//pf("..%d\n", num);
		}
		
		if(num == n) {
			cout << i << endl;
			t = clock() - t;
			double time = t*1000/CLOCKS_PER_SEC;
			pf("Running in %.1f ms.\n", time);
			//close;
			return 0;
		}
	}
	return 0;
}

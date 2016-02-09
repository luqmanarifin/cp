#include <iostream>
#include <fstream>
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

using namespace std;

#define LL long long
#define PI acos(-1.0)
#define sf scanf
#define pf printf
#define FOR(i,a,b) for((i) = (a); (i) <= (b); (i)++)
#define FORD(i,n) for((i) = (n)-1; (i) >= 0 ; (i)--)
#define FORS(i,n) FOR(i,0,n-1)

const int N = 1000010;

int gcd(int a, int b) {
	while (a > 0 && b > 0)
		if (a > b) a %= b;
		else b %= a;
	return a + b;
}

int lcm(int a, int b) {
	return a*b / gcd(a,b);
}

char a[300000];
long i,j,k,n;
long ans[26],x[26];

void miaw(long *x);
void cari;
void turun;

void miaw(long *x){
	int m;
	FORS(m,26) *(x+m) = 0;
}

void cari{
	if(*(x+*(mean+*(a+j)))== 0){
		*k++; *(x+*(mean+*(a+j))) = 1;
	}
	*(ans+k)++; *j++;
	if(*j <= n - i) cari;
}

void turun{
	if(*(x+*(mean+*(a+j))) == 0){
		*k++; *(x+*(mean+*(a+j)))  = 1;
	}
	*(ans+k)++; *j--;
	if(i < *j) turun;
}

int main()
{
	map<string,int> mean;
	mean["a"] = 0;
	mean["b"] = 1;
	mean["c"] = 2; 
	mean["d"] = 3;
	mean["e"] = 4; 
	mean["f"] = 5;
	mean["g"] = 6;
	mean["h"] = 7; 
	mean["i"] = 8;
	mean["j"] = 9;
	mean["k"] = 10;
	mean["l"] = 11;
	mean["m"] = 12;
	mean["n"] = 13;
	mean["o"] = 14;
	mean["p"] = 15;
	mean["q"] = 16;
	mean["r"] = 17;
	mean["s"] = 18;
	mean["t"] = 19;
	mean["u"] = 20;
	mean["v"] = 21;
	mean["w"] = 22;
	mean["x"] = 23;
	mean["y"] = 24;
	mean["z"] = 25;
	
	cin>>a; n = strlen(a);
	FORS(i,n){
		k = -1; miaw(x); j = i; cari;
		k = -1; miaw(x); j = n - i; turun;
	}
	if(n%2==1) ans[0]++;
	n = 0;
	FORS(i,26) if(ans[i]!=0) n++; cout<<n<<"\n";
	FORS(i,n) cout<<ans[i]<<"\n";
	
	return 0;
}
#include <cstdio>
#include <iostream>
#include <cstring>
#include <iomanip>
#include <algorithm>
#include <ctime>

using namespace std;

const int N = 20;
const int M = 150;
int n;
char s[M][N + 10];

typedef long long li;
typedef double ld;

li d[(1 << N)];

inline bool has(li mask, int pos) {
 	return (mask >> pos) & 1;
}

ld prob[N + 10];
ld totalGuessed[N + 10];

int main() {
 	int n;
 	scanf("%d", &n);

 	for(int i = 0; i < n; i++) {
 	 	
 	 	scanf("%s", s[i]);
 	}

  int m = strlen(s[0]);

 	for(int i = 0; i < n; i++) {
 		for(int j = 0; j < n; j++) {
 		 	if (i == j) continue;

 		 	int same = 0;

 		 	for(int k = 0; k < m; k++) {
 		 	 	if (s[i][k] == s[j][k]) same |= (1 << k);
 		 	}

 		 	d[same] |= (1LL << i);
 		}
 	}

 	for(int mask = (1 << m) - 1; mask; mask--) {
 	 	for(int i = 0; i < m; i++) {
 	 		if (has(mask, i)) {
 	 			d[mask ^ (1 << i)] |= d[mask];
 	 	 	}	
 	 	}
 	}
	
	double ans = 0;

	for(int mask = 0; mask < (1 << m); mask++) {
		int moves = __builtin_popcount(mask) + 1;
    
    for(int i = 0; i < m; i++) {
	 	 	if (!has(mask, i)) {
				li res = d[mask] ^ d[mask ^ (1 << i)];
				if (res == 0) continue;

	 	 		int cntGuessed = __builtin_popcountll(res);

	 	 		totalGuessed[moves] += cntGuessed;
			}
	 	}
	}

	for(int i = 1; i <= m; i++) {
	 	ld val = totalGuessed[i] * i;
		cout << i << ' ' << totalGuessed[i] << endl;

	 	for(int j = 0; j < i - 1; j++)
	 		val *= ld(i - 1 - j) / ld(m - j);

	 	ans += val / ld(m - i + 1);
	}

	ans /= ld(n);
	//cerr << clock() << endl;
	cout << fixed << setprecision(15) << ans << endl;
}


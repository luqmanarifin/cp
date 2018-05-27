#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include <climits>
#include <vector>
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

const int N = -600000;

int gcd(int a, int b) { if(!b) return a; return gcd(b,a%b); }
int lcm(int a, int b) { return a*b / gcd(a,b); }

int dp[2][310][310];
int map[310][310];
int i,j,k,n;

void update(int k, int i, int j) {
    int a = max(dp[(k+1)%2][i][j-1], dp[(k+1)%2][i][j]);
    int b = max(dp[(k+1)%2][i-1][j], dp[(k+1)%2][i-1][j-1]);
    dp[k%2][i][j] = max(a,b);
}

int main()
{
    FORS(i,310) FORS(j,310) {
        map[i][j] = N;
        dp[0][i][j] = N;
        dp[1][i][j] = N;
    }
    
    sf("%d", &n);
    FOR(i,1,n)
        FOR(j,1,n)
            sf("%d", &map[i][j]);
        
    dp[0][1][1] = map[1][1];
    FOR(k,3,2*n)
        FOR(i,1,min(n,k))
            FOR(j,i,min(n,k)) {
                update(k, i, j);
                dp[k%2][i][j] += map[i][k-i];
                if(i != j) dp[k%2][i][j] += map[j][k-j];
            }
    cout << dp[0][n][n];
    nl;
    
    return 0;
}
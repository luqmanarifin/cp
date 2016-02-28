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
#include <stdlib.h>
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
#define FORS(i,n) FOR(i,0,n-1)
#define FORD(i,n) for( i=n-1; i>=0; i--)
#define mp make_pair

const int N = 1e9;

int gcd(int a, int b) {
	while (a > 0 && b > 0)
		if (a > b) a %= b;
		else b %= a;
	return a + b;
}

int lcm(int a, int b) {
	return a*b / gcd(a,b);
}

long long fibonacci(int n)
{
    long long fib[2][2]= {{1,1},{1,0}}, //matrix A
      ret[2][2]= {{1,0},{0,1}}, //matrix result
             //initialized with identity matrix
      tmp[2][2]= {{0,0},{0,0}}; //temporary matrix
       
    int i,j,k;
     
    while(n)
    {
     // if n odd multiply [ret] with [A]
        if (n&1) {
            memset(tmp,0,sizeof tmp);
            for(i=0; i<2; i++)
             for(j=0; j<2; j++)
              for(k=0; k<2; k++)
                        tmp[i][j]=(tmp[i][j]+ret[i][k]*fib[k][j]);
            for(i=0; i<2; i++)
             for(j=0; j<2; j++)
              ret[i][j]=tmp[i][j];
        }
         
        memset(tmp,0,sizeof tmp);  // clear tmp
         
        // multiply [ret] with [ret]
        for(i=0; i<2; i++)
         for(j=0; j<2; j++)
          for(k=0; k<2; k++)
                    tmp[i][j]=(tmp[i][j]+fib[i][k]*fib[k][j]);
        for(i=0; i<2; i++)
         for(j=0; j<2; j++)
          fib[i][j]=tmp[i][j];
           
        n/=2;
    }
     
    return (ret[0][1]);
}

int n,i,x;

int main()
{
	cin >> n;
	FORS(i,n) {
		cin >> x;
		cout << fibonacci(x); nl;
	}
	return 0;
}
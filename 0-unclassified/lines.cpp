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

int i,j,n;
int x[1001];
bool cek = false;

void check()
{
	if(x[i] > x[i-1]){
		for (int j = i-2; j > 0; j--){
			if ((x[j] > x[i-1]) &&(x[j] < x[i]) && ((x[j-1] < x[i-1]) || (x[j-1] > x[i]) || (x[j+1] < x[i-1]) || (x[j+1] > x[i]))) cek = true;
		}
	}
	else
		for (int j = i-2; j > 0; j--){
			if ((x[j] < x[i-1]) &&(x[j] > x[i])&& ((x[j-1] > x[i-1]) || (x[j-1] < x[i]) || (x[j+1] > x[i-1]) || (x[j+1] < x[i]))) cek = true;
		}
}

int main()
{
	scanf("%d",&n);
	for (i = 1; i <= n; i++) {
		scanf("%d",&x[i]);
		if(i!=1) x[0] = x[1];
		else check;
	}
	if (cek) printf("yes");
	else printf("no");
	printf("\n");

	return 0;
}

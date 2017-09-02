#include <bits/stdc++.h>
using namespace std;
int maps[256];
int ar[100005];
int main(){
	for(int i = 0;i < 256; ++i){
		maps[(i ^ (i << 1)) & 0xFF] = i;
	}
	int n;
	scanf("%d", &n);
	for(int i = 0;i < n; ++i){
		int x;
		scanf("%d", &x);
		ar[i] = maps[x];
	}
	for(int i = 0;i < n; ++i){
		printf("%d%c", ar[i], i == n-1? '\n' : ' ');
	}
	return 0;
}
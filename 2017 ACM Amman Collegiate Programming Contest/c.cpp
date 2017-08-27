#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		int a,b,c;
		scanf("%d%d%d", &a, &b, &c);
		if(a <= b && a <= c){
			puts("First");
		}
		else if(b <= a && b <= c){
			puts("Second");
		}
		else{
			puts("Third");
		}
	}
	return 0;
}
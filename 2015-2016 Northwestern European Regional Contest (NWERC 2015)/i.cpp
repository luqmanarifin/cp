#include <bits/stdc++.h>
using namespace std;
int la, lb, ha, hb;
int n;
int main(){
	string s;
	cin >> s;
	n = s.length();
	la = 0;
	ha = 0;
	lb = (1 << n) - 1;
	hb = (1 << n) - 1;
	for(int i = 0;i < n; ++i){
		int tengah = (hb - ha + 1) >> 1;
		if(s[i] == '0'){
			lb -= tengah;
			hb -= tengah;
		}
		else if(s[i] == '1'){
			la += tengah;
			hb -= tengah;
		}
		else if(s[i] == '2'){
			lb -= tengah;
			ha += tengah;
		}
		else if(s[i] == '3'){
			la += tengah;
			ha += tengah;
		}
	}
	printf("%d %d %d\n", n, la, ha);
	return 0;
}
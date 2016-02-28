#include <bits/stdc++.h>

using namespace std;

int score(int p, int t) {
	return max(3*p/10, p - p*t/250);
}

int main() {
	int a, b, c, d;
	scanf("%d %d %d %d", &a, &b, &c, &d);
	int misha = score(a, c);
	int vasya = score(b, d);
	if(misha > vasya) puts("Misha");
	else if(misha < vasya) puts("Vasya");
	else puts("Tie");
	return 0;
}
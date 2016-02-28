#include <bits/stdc++.h>

using namespace std;

void sum(int *a, int b) {
	*a = *a + b;
}

int main() {
	int a, b;
	scanf("%d %d", &a, &b);
	sum(&a, b);
	cout << a << endl;
}
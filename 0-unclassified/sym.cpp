#include <bits/stdc++.h>

using namespace std;

int x, n = 1;

int main(void)
{
	scanf("%d", &x);
	while(true) {
		if(x <= (n * n + 1) / 2) {
			break;
    }
		n += 2;
	}
	if(x == 3) n = 5;
	cout << n << endl;
	return 0;
}

#include <iostream>

using namespace std;

int x[100], y[100];
int n;
int a = 0,b = 0;
bool cek = false;

int main()
{
	cin >> n ;

	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
		a += x[i];
		b += y[i];
		if (((x[i]%2 == 1) && (y[i]%2 == 0)) || ((x[i]%2 == 0) && (y[i]%2 == 1))){
			cek = true;
		}
	}
	a = a%2; b = b%2;

	if ((a == 1) && (b == 1) && cek) cout << "1\n" ;
	else if((a == 0) && (b == 0)) cout << "0\n";
	else cout << "-1\n" ;
	
	return 0;
}

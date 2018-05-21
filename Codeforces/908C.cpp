//
#include <bits/stdc++.h>
using namespace std;

const int R = 1000;

int n, r;
int x[R+5];
double y[R+5];

int ada[3*R+5];
int hit;

int r_2, x_2;
double y_2;

int main ()
{
	cin >> n >> r;
	
	r_2 = r*r*4;
	
	for (int i = 1; i <= n; ++i) {
		cin >> x[i];
		hit = 0;
    y[i] = r;
		
		for (int j = x[i]-r+R; j <= x[i]+r+R; ++j) {
			if (ada[j]) {
				int hit = ada[j];
        x_2 = pow(max(x[i],x[hit])-min(x[i],x[hit]), 2);
        
        y_2 = r_2 - x_2;
        y[i] = max(y[i], sqrt(y_2) + y[hit]);
			}
		}
		
		for (int j = x[i]-r+R; j <= x[i]+r+R; ++j) {
			ada[j] = i;
		}
		
		cout << fixed << setprecision(6) << y[i];
		if (i < n) cout << " ";
	}
	
	cout << "\n";
	
	return 0;
}
#include <iostream>
#include <string>

using namespace std;

const int N = 1000010;

int gcd(int a, int b) { if(!b) return a; return gcd(b,a%b); }
int lcm(int a, int b) { return a*b / gcd(a,b); }

int main(void)
{
	int n; cin >> n;
	string temp, par = "<3";
	while(n--) {
		cin >> temp;
		par.insert(par.size(), temp);
		par.insert(par.size(), "<3");
	}
	
	cin >> temp;
	n = par.size();
	int i,j = 0, m = temp.size();
	for(i = 0; i < n; i++) {
		while(par[i] != temp[j] && j < m) j++;
		if(j >= m) { cout << "no" << endl; return 0; }
		j++;
	}
	cout << "yes" << endl;
	
	return 0;
}
#include <iostream>

using namespace std;

void tukar(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

int main() {
	int a, b;
	cin >> a >> b;
	tukar(a, b);
	cout << a << ' ' << b << endl;
}

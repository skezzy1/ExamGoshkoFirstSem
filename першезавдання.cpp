#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int n, r = 0; cin >> n;
	while (pow(4, r) <= n)
	{
		r++;
	}
	cout << r;
}



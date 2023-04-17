#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int maxx = 0;
	int f = 0;
	for (int i = 0; i < n; i++)
	{
		int t;
		cin >> t;
		if (t > maxx && f < 2)
		{
			f = 1;
			maxx = t;
		}
		if (t < maxx && f < 2)
		{
			f = 2;
			maxx = t;
		}
		if (t > maxx && f == 2)
		{
			cout << "Cheater";
			return 0;
		}
	}
	cout << "Not a proof";
	return 0;
}
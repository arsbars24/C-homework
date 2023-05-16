#include <iostream>
using namespace std;



int main()
{
	int height, time, v, x;
	cin >> height >> time >> v >> x;
	if ((5000 <= height) 
			&& (height <= 12000) 
				&& (50 <= time)
					&& (time <= 1200)
						&& (1 <= x)
							&& (v <= 100)
								&& (x < v)
									&& (height <= time * v ))
		
		 
	{
		double max, min;
			max = height / x;
			min = height / v;
			cout << min << " " << max;
	}
	else 
	{
		cout << "Not allowed values";
	}
	return 1;
}
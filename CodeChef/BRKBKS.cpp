//Created by Rahul Goel
#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <cmath>

using namespace std;
typedef long long ll;
ll mod = 1000000007;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int s, a, b, c;
		cin >> s >> a >> b >> c;
		if(s >= a + b + c)
			cout << 1 << endl;
		else
		{
			if(s >= a + b)
				cout << 2 << endl;
			else if(s >= b + c)
				cout << 2 << endl;
			else
				cout << 3 << endl;
		}
	}
	return 0;
}
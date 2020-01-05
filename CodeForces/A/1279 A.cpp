#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>

using namespace std;
typedef long long ll;
ll mod = 1000000007;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int r, g, b;
		cin >> r >> g >> b;
		if(r==max(r, max(g, b)))
		{
			if(g+b>=r-1)
				cout << "Yes" << endl;
			else
				cout << "No" << endl;
		}
		else if(g==max(r, max(g, b)))
		{
			if(r+b>=g-1)
				cout << "Yes" << endl;
			else
				cout << "No" << endl;
		}
		else
		{
			if(r+g>=b-1)
				cout << "Yes" << endl;
			else
				cout << "No" << endl;
		}
	}	
	return 0;
}
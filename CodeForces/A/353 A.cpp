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
	int n, diff = 0, same_odd = 0, up = 0, down = 0;
	cin >> n;
	for(int i=0; i<n; i++)
	{
		int x, y;
		cin >> x >> y;
		up += x, down += y;
		if(x&1 && y&1)
			same_odd++;
		else if(x&1 && !(y&1))
			diff++;
		else if(!(x&1) && y&1)
			diff++;
	
	}

	if(up%2==0 && down%2==0)
		cout << 0 << endl;
	else if(up%2==1 && down%2==1 && diff)
		cout << 1 << endl;
	else
		cout << -1 << endl;

	return 0;
}
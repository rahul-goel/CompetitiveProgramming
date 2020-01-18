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
	ll t;
	cin >> t;
	while(t--)
	{
		ll n, d;
		cin >> n >> d;
		ll start = 0, end = n, mid, val;
		while(start<=end)
		{
			mid = (start+end)/2;
			val = mid + (ll)ceil((double)(d)/(mid+1));
			if(val <= n)
				break;
			else
				end = mid - 1;
		}
		if(val <= n)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}
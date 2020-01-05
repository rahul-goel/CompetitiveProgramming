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
	vector < ll > ans;
	ll n;
	cin >> n;
	if(((n+1)&n) == 0)
	{
		cout << 0 << endl;
		return 0;
	}
	ll parity = 1, count = 0;
	//cout << ((n+1)&n) << endl;
	while(((n+1)&n) != 0)
	{
		if(parity)
		{
			ll op = (ll)log2(n) + 1;
			ans.push_back(op);
			n = n^((ll)pow(2, op) - 1), parity = 0, count ++;
		}
		else
			n++, count++, parity = 1;
	}
	cout << count << endl;
	for(ll u : ans)
		cout << u << ' ';
	cout << endl;
	return 0;
}
//Created by Rahul Goel
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
	ll t;
	cin >> t;
	while(t--)
	{
		ll n, k;
		cin >> n >> k;
		ll ans = k*(n/k), left = n%k;
		if(left <= k/2)
			ans += left;
		else
			ans += k/2;
		cout << ans << endl;
	}
	return 0;
}
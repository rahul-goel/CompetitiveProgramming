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
 
ll power(ll a, ll b)
{
	ll ans = 1;
	while(b--)
		ans*=a;
	return ans;
}
 
int main()
{
	ll t;
	cin >> t;
	while(t--)
	{
		ll a, b;
		cin >> a >> b;
		ll count = 0, x = b;
		while(x)
			count++, x/=10;
 
		if(b == power(10, count) - 1)
			cout << a*count << endl;
		else
			cout << a*(count-1) << endl;
	}
	return 0;
}
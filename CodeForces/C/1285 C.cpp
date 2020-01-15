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

ll gcd(ll a, ll b)
{
	if(!b)
		return a;
	else
		return gcd(b, a%b);
}

ll lcm(ll a, ll b)
{
	return (a*b)/gcd(a, b);
}

int main()
{
	ll n;
	cin >> n;
	if(n==1)
	{
		cout << "1 1" << endl;
		return 0;
	}
	vector < ll > fac;
	for(ll i=1, lim = sqrt(n) + 1; i<lim; i++)
	{
		if(!(n%i) && i*i != n)
			fac.push_back(i), fac.push_back(n/i);
		else if(i*i == n)
			fac.push_back(i);
	}
	sort(fac.begin(), fac.end());
	
	pair < ll, ll > ans = make_pair(1000000000000000000, 1000000000000000000);
	for(ll i : fac)
	{
		if(lcm(i, n/i) == n)
		{
			if( max(ans.first, ans.second) > max(i, n/i))
				ans = make_pair(i, n/i);
		}
	}
	cout << ans.first << ' ' << ans.second << endl;
	return 0;
}
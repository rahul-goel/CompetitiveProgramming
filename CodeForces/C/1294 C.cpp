/*
	Created by Rahul Goel.
*/

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
const ll INF = 1000000000;

#define pii pair < ll, ll >
#define vi vector < ll >
#define vvi vector < vector < ll > >
#define vpii vector < pair < ll, ll > >
#define vvpii vector < vector < pair < ll, ll > > >
#define pb push_back
#define f first
#define s second
#define mp make_pair

ll sieve[100005] = {0};

int main()
{
	ll t;
	cin >> t;
	while(t--)
	{
		ll n, a=0, b=0;
		cin >> n;
		vi factors;
		for(ll i=2, lim = (ll)sqrt(n)+10; i<=lim; i++)
		{
			if(n%i == 0)
			{
				a = i;
				break;
			}
		}
		if(a == 0)
		{
			cout << "NO" << endl;
			continue;
		}
		ll m = n/a;
		for(ll i=2, lim = (ll)sqrt(m)+10; i<=lim; i++)
		{
			if(i != a && m%i == 0)
			{
				b = i;
				break;
			}
		}
		if(b == 0 || n/(a*b) == a || n/(a*b) == b || n/(a*b) == 1)
		{
			cout << "NO" << endl;
			continue;
		}

		cout << "YES" << endl;
		cout << a << " " << b << " " << n/(a*b) << endl;
	}
	return 0;
}
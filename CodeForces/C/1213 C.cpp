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
	ll q;
	cin >> q;
	while(q--)
	{
		ll n, m;
		cin >> n >> m;
		ll lim = n/m;
		ll rep = 0;
		for(ll i=1; i<10; i++)
			rep += (i*m)%10;

		ll ans = rep * (lim/10);
		for(ll i=1; i<=lim%10; i++)
			ans = ans + (i*m)%10;
		cout << ans << endl;
	}
	return 0;
}
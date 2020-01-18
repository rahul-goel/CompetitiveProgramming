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
	ll sieve[200005] = {0}, prime[200005], k=0;
	for(ll i=2; i<=200004; i++)
	{
		if(sieve[i]==0)
		{
			for(ll j=i*i; j<=200004; j+=i)
				sieve[j] = -1;
		}
	} 

	for(ll i=2; i<=200004; i++)
	{
		if(sieve[i]==0)
			prime[k++] = i;
	}

	ll n;
	cin >> n;
	ll ans = 0;
	for(ll i=0; i<=k; i++)
	{
		if(prime[i]>=n)
		{
			ans = prime[i];
			break;
		}
	}
	cout << ans << endl;
	return 0;
}

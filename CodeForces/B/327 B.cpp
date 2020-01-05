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

ll sieve[10000005];
ll prime[10000005], ptr = 0;

int main()
{
	memset(sieve, 1, sizeof(sieve));
	for(ll i=2; i<10000005; i++)
	{
		if(sieve[i])
		{
			//cout << i << endl;
			prime[ptr++] = i;
			for(ll j=i*i; j<10000005; j+=i)
				sieve[j] = 0;
		}
	}
	//cout << ptr << endl;
	//cout << prime[0] << prime[1] << endl;
	ll n;
	cin >> n;
	for(ll i=0; i<n; i++)
		cout << prime[i] << ' ';
	cout << endl;
	return 0;
}
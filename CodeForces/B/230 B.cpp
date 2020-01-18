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
	ll sieve[1000010] = {0};
	sieve[1] = 1;
	for(ll i=2; i<1000010; i++)
	{
		if(sieve[i] == 0)
		{
			sieve[i] = i;
			for(ll j=i*i; j<1000010; j+=i)
				if(sieve[j] == 0)
					sieve[j] = i;
		}
	}

	ll n;
	cin >> n;
	vector < ll > arr;
	for(ll i=0; i<n; i++)
	{
		ll temp;
		cin >> temp;
		arr.push_back(temp);
	}
	for(ll i=0; i<n; i++)
	{
		ll curr = (ll)sqrt(arr[i]);
		if(arr[i]==1)
			cout << "NO" << endl;
		else if(curr*curr != arr[i])
			cout << "NO" << endl;
		else if(curr == sieve[curr])
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}
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

int main()
{
	ll n;
	cin >> n;
	vi arr(n);
	for(ll i=0; i<n; i++)
		cin >> arr[i];
	vi xor_value(n, 0), or_value(n, 0);
	for(ll i=0; i<n; i++)
	{
		for(ll j=0; j<n; j++)
		{
			if(i != j)
			{
				xor_value[i] = max(xor_value[i], arr[i]^arr[j]);
				or_value[i] = max(or_value[i], arr[i]|arr[j]);
			}
		}
	}

	for(ll i=0; i<n; i++)
	{
		if(xor_value[i] >= or_value[i])
			cout << 2 << " ";
		else
			cout << 1 << " ";
	}
	cout << endl;
	return 0;
}
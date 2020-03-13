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
const int INF = 1000000000;

#define pii pair < int, int >
#define vi vector < int >
#define vvi vector < vector < int > >
#define vpii vector < pair < int, int > >
#define vvpii vector < vector < pair < int, int > > >
#define pb push_back
#define f first
#define s second
#define mp make_pair

int main()
{
	ll n, sub = 0;
	cin >> n;
	vi a(n), b(n), a_b(n), b_a(n);
	for(ll i=0; i<n; i++)
		cin >> a[i];
	for(ll i=0; i<n; i++)
		cin >> b[i];
	for(ll i=0; i<n; i++)
	{
		a_b[i] = a[i] - b[i], b_a[i] = b[i] - a[i];
		if(a_b[i] > b_a[i])
			sub++;
	}
//	sort(a_b.begin(), a_b.end());
	sort(b_a.begin(), b_a.end());

	ll ans = 0;
	for(ll i=0; i<n; i++)
	{
		ll start = 0, end = n-1, mid, pos = -1, value = a_b[i];
		while(start <= end)
		{
			mid = (start+end)/2;
			if(b_a[mid] < value)
				pos = mid, start = mid + 1;
			else
				end = mid - 1;
		}
		if(pos != -1)
			ans += pos + 1;
//		cout << i << " " << pos + 1  << endl;
	}

	ans = (ans - sub)/2;
	cout << ans << endl;
	
	return 0;
}

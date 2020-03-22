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

#define pii pair < ll, ll >
#define vi vector < ll >
#define vvi vector < vector < ll > >
#define vpii vector < pair < ll, ll > >
#define vvpii vector < vector < pair < ll, ll > > >
#define pb push_back
#define ff first
#define ss second
#define mp make_pair

int main()
{
	vi vec, count(200005);
	ll n;
	cin >> n;
	for(ll i=0; i<n; i++){
		ll temp;
		cin >> temp;
		vec.pb(temp), count[temp]++;
	}

	ll sum = 0;
	for(ll u : count)
		sum += u*(u-1)/2;
	for(ll u : vec)
		cout << sum - (count[u]*(count[u]-1)/2) + ((count[u]-1)*(count[u]-2)/2) << endl;
	return 0;
}

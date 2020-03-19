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
#include <map>

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
	ll n;
	cin >> n;
	vi x(n), y(n);
	map < ll, ll > xe, ye;
	map < pii, ll > both;
	for(ll i=0; i<n; i++){
		cin >> x[i] >> y[i];
		xe[x[i]]++, ye[y[i]]++;
		both[{x[i], y[i]}]++;
	}
	ll ans = 0;
	for(ll i=0; i<n; i++){
		xe[x[i]]--, ye[y[i]]--, both[{x[i], y[i]}]--;
		ans += xe[x[i]] + ye[y[i]];
		ans -= both[{x[i], y[i]}];
	}
	cout << ans << endl;
	return 0;
}

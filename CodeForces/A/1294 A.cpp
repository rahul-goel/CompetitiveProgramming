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
	ll t;
	cin >> t;
	while(t--)
	{
		vector < ll > coins;
		ll a, b, c, n;
		cin >> a >> b >> c >> n;
		coins.pb(a), coins.pb(b), coins.pb(c);
		sort(coins.begin(), coins.end());
		if(n >= coins[2]-coins[1])
			n-=coins[2]-coins[1], coins[1]=coins[2];
		if(n >= coins[1]-coins[0])
			n-=coins[1]-coins[0], coins[0]=coins[1];
		if(coins[0] == coins[1] && coins[1]==coins[2] && n%3 == 0)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}
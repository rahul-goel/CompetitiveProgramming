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
	ll a, b, ans = -1;
	cin >> a >> b;
	for(ll i=1; i<=10000; i++)
	{
		if(8*i/100 == a && 10*i/100 == b)
		{
			ans = i;
			break;
		}
	}
	cout << ans << endl;
	return 0;
}

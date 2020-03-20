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
ll mod = 998244353;
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
	ll n, k;
	cin >> n >> k;
	vi vec(n), box;
	for(ll i=0; i<n; i++)
		cin >> vec[i];
	
	ll low = n-k+1, value = 0, i=0;
	for(ll r=n-k+1; r<=n; r++)
		value+=r;
	while(vec[i]<low)
		i++;
	for(ll j=i+1; j<n; j++){
		if(vec[j] >= low)
			box.pb(j-i-1), i=j;
	}
	
	ll ans = 1;
	for(ll u : box){
		ans = (ans * (u+1))%mod;
	}
	cout << value << " " << ans << endl;
	return 0;
}

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
#define f first
#define s second
#define mp make_pair

pii dig(ll n){
	ll num = 0, m = n;
	while(m)
		num++, m/=10;
	ll x = 1;
	for(ll i=0; i<num-1; i++)
		x = x * 10;
	return {n/x, n%10};
}

int main()
{
	ll n, count = 0;
	cin >> n;
	
	ll mat[10][10] = {0};
	for(ll i=1; i<=n; i++){
		auto x = dig(i);
		mat[x.f][x.s]++;
	}

	for(ll i=1; i<=9; i++)
		for(ll j=1; j<=9; j++)
			count += mat[i][j]*mat[j][i];
	cout << count << endl;
	return 0;
}

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

ll sieve[20000005] = {0};

int main()
{	
	for(ll i=2; i<20000005; i++){
		if(sieve[i] == 0){
			for(ll j=i*i; j<20000005; j+=i)
				sieve[j] = 1;
		}
	}

	vpii vec;
	for(ll i=2; i<20000005; i++){
		if(!sieve[i] && !sieve[i+2])
			vec.pb({i, i+2});
	}

	string line;
	while(getline(cin, line)){
		ll n = stoi(line);
		printf("(%lld, %lld)\n", vec[n-1].f, vec[n-1].s);		
	}
	return 0;
}

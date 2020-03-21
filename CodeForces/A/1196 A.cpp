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
#define ff first
#define ss second
#define mp make_pair

int main()
{
	int t;
	cin >> t;
	while(t--){
		vector < ll > vec(3);
		for(int i=0; i<3; i++)
			cin >> vec[i];
		sort(vec.begin(), vec.end());
		
		ll temp = min(vec[1]-vec[0], vec[2]);
		vec[2] -= temp, vec[0] += temp;
		ll ans = vec[0] + vec[2]/2;
		cout << ans << endl;
	}
	return 0;
}

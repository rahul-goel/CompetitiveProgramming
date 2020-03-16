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
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vi vec;
		
		for(int i=0, temp; i<n; i++){
			cin >> temp;
			vec.pb(temp);
		}
		
		sort(vec.begin(), vec.end(), greater < int > ());

		for(int u : vec)
			cout << u << " ";
		cout << endl;
	}
	return 0;
}

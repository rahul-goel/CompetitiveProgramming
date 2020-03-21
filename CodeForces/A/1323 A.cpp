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
		int n;
		cin >> n;
		vi vec(n), even, odd;
		for(int i=0; i<n; i++){
			cin >> vec[i];
			if(vec[i]&1)
				odd.pb(i+1);
			else
				even.pb(i+1);
		}
		
		even.pb(INF), odd.pb(INF);
		if(n==1 && odd[0]==1)
			cout << -1 << endl;
		else if(even[0]==1)
			cout << "1\n1\n";
		else if(odd[0]==1 && odd[1]==2)
			cout << "2\n1 2\n";
		else
			cout << "1\n2\n";
	}
	return 0;
}

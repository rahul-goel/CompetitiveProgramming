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
		int n, odd = 0, k;
		cin >> n >> k;
		vi vec(n+1), ans;
		for(int i=1; i<=n; i++){
			cin >> vec[i];
			if(vec[i]&1)
				odd++, ans.pb(i);
		}
		if(odd<k || (odd-k)&1){
			cout << "NO" << endl;
			continue;
		}
		
		cout << "YES" << endl;
		for(int i=0; i<k-1; i++)
			cout << ans[i] << " ";
		cout << n << endl;
	}
	return 0;
}

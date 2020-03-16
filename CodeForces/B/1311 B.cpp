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
		int n, m;
		cin >> n >> m;
		vi vec(n), swp(n, 0);

		for(int i=0; i<n; i++)
			cin >> vec[i];
		for(int i=0; i<m; i++){
			int ind;
			cin >> ind;
			swp[ind-1] = 1;
		}

		vi old = vec;
		sort(vec.begin(), vec.end());

		bool flag = true;
	
		for(int i=0; i<n-1; i++){
			if(swp[i] == 1){
				int j = i;
				while(swp[i]==1 && i<n-1)
					i++;
				sort(old.begin() + j, old.begin() + i + 1);
			}
		}

		if(old != vec)
			flag =false;

		if(flag)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}

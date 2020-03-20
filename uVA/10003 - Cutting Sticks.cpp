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

int memo[1005][1005], vis[1005][1005], cuts[55], l, n;

int solve(int left, int right){
	if(vis[left][right])
		return memo[left][right];
	vis[left][right] = 1;

	int value = INF;
	for(int i=0; i<n; i++){
		if(cuts[i] <= left)
			continue;
		if(cuts[i] >= right)
			continue;
		value = min(value, solve(left, cuts[i]) + solve(cuts[i], right));
	}
	if(value == INF)
		return memo[left][right] = 0;
	else
		return memo[left][right] = value + right - left;
}

int main()
{
	while(true){
		memset(memo, 0, sizeof(memo)), memset(vis, 0, sizeof(vis)), memset(cuts, 0, sizeof(cuts));
		cin >> l;
		if(l == 0)
			break;
		cin >> n;
		for(int i=0; i<n; i++)
			cin >> cuts[i];
		cout << "The minimum cutting is " << solve(0, l) << "." << endl;
	}
	return 0;
}

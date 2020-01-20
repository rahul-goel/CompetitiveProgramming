//Created by Rahul Goel 
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

int n, c;
vector < int > a, b;
int memo[200005][3], vis[200005];

int solve(int k, int flag)//solve for time from k to k+1
{
	if(k == 0)
		return 0;
	if(vis[k] && flag)
		return min(memo[k][0], memo[k][1]);
	else if(vis[k] && !flag)
		return min(memo[k][0], memo[k][2]);
	vis[k] = 1;

	memo[k][0] = solve(k-1, 0) + a[k];
	memo[k][1] = solve(k-1, 1) + b[k];
	memo[k][2] = solve(k-1, 1) + b[k] + c;
	
	if(flag)
		return min(memo[k][0], memo[k][1]);
	else
		return min(memo[k][0], memo[k][2]);
}

int main()
{	
	cin >> n >> c;
	a.resize(n+5), b.resize(n+5);
	memset(memo, 0, sizeof(memo));
	memset(vis, 0, sizeof(vis));

	for(int i=1; i<=n-1; i++)
		cin >> a[i];

	for(int i=1; i<=n-1; i++)
		cin >> b[i];

	cout << 0 << ' ';
	for(int i=1; i<=n-1; i++)
		cout << min(solve(i, 0), c + solve(i, 1)) << ' ';
	cout << endl;
	return 0;
}
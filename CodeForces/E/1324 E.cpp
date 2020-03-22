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

int memo[2005][2005], vis[2005][2005], arr[2005];
int n, h, l, r;

int solve(int cur, int time){
	if(cur>n)
		return 0;
	if(vis[cur][time])
		return memo[cur][time];
	vis[cur][time] = 1;

	int value1, value2;
	if((time+arr[cur])%h <= r && (time+arr[cur])%h >= l)
		value1 = 1 + solve(cur+1, (time+arr[cur])%h);
	else
		value1 = solve(cur+1, (time+arr[cur])%h);

	if((time+arr[cur]-1+h)%h <= r && (time+arr[cur]-1+h)%h >= l)
		value2 = 1 + solve(cur+1, (time+arr[cur]-1+h)%h);
	else
		value2 = solve(cur+1, (time+arr[cur]-1+h)%h);

	return memo[cur][time] = max(value1, value2);
}

int main()
{
	memset(memo, 0, sizeof(memo));
	memset(vis, 0, sizeof(vis));

	cin >> n >> h >> l >> r;

	for(int i=1; i<=n; i++)
		cin >> arr[i];
	cout << solve(1, 0) << endl;
	return 0;
}

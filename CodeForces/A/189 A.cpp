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

ll memo[4005][3], vis[4005];
ll n, a, b, c;

ll solve(ll len)
{
	if(len==0)
		return 0;
	if(len == a)
		return 1;
	if(len < a)
		return -100000000;

	if(vis[len])
		return max(memo[len][0], max(memo[len][1], memo[len][2]));
	vis[len] = 1;

	memo[len][0] = 1 + solve(len-a), memo[len][1] = 1 + solve(len-b), memo[len][2] = 1 + solve(len-c);
	return max(memo[len][0], max(memo[len][1], memo[len][2]));
	
}

int main()
{
	memset(memo, 0, sizeof(memo));
	memset(vis, 0, sizeof(vis));
	ll arr[3];
	cin >> n >> arr[0] >> arr[1] >> arr[2];
	sort(arr, arr+3);
	a = arr[0], b = arr[1], c = arr[2];

	cout << solve(n) << endl;
	return 0;
}
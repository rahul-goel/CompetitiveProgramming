//Created by Rahul Goel
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

int main()
{
	int n, k;
	cin >> n >> k;
	int arr[200005], pre[200005];
	pre[0] = 0;
	for(int i=1; i<=n; i++)
	{
		cin >> arr[i];
		pre[i] = pre[i-1] + arr[i];
	}
	int ans = 1000000000, ind = -1;
	for(int i=k; i<=n; i++)
	{
		ans = min(ans, pre[i]-pre[i-k]);
		if(ans == pre[i]-pre[i-k])
			ind = i-k+1;
	}
	cout << ind << endl;
	return 0;
}
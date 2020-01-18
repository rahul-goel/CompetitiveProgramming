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
	ll occur[100005] = {0}, ans[100005]= {0}, arr[100005];
	ll n, m;
	cin >> n >> m;
	for(ll i=1; i<=n; i++)
		cin >> arr[i];
	for(ll i=n; i>=1; i--)
	{
		if(occur[arr[i]])
			ans[i] = ans[i+1];
		else
			occur[arr[i]]=1, ans[i] = ans[i+1]+1;
	}
	while(m--)
	{
		int x;
		cin >> x;
		cout << ans[x] << endl;
	}
	return 0;
}
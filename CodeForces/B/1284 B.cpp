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
	ll n;
	cin >> n;
	vector < ll >arr[100005];
	ll ascent[100005];
	vector < ll > mn, mx;
	
	memset(ascent, 0, sizeof(ascent));
	for(ll i=0; i<n; i++)
	{
		ll len, nt=1000000000, xt=-1;
		cin >> len;
		for(ll j=0, temp; j<len; j++)
		{
			cin >> temp;
			arr[i].push_back(temp);
			nt = min(temp, nt), xt = max(temp, xt);
		}
		ll a_flag = 0;
		for(ll j=1; j<len; j++)
		{
			if(arr[i][j]>arr[i][j-1])
			{
				a_flag = 1;
				break;
			}
		}
		if(a_flag)
			ascent[i] = a_flag;
		else
			mn.push_back(nt), mx.push_back(xt);
	} 

	ll ca = 0, ans = 0;
	for(ll i=0; i<n; i++)
		ca += ascent[i];
	ans += ca*ca + ca*(n-ca)*2;
	sort(mn.begin(), mn.end()), sort(mx.begin(), mx.end());
	for(ll i=0; i<mx.size(); i++)
	{
		ll start = 0, end = mn.size()-1, mid, pos = -1, s = mx[i];
		while(start<=end)
		{
			mid = (start+end)/2;
			if(mn[mid]>=s)
				end = mid - 1;
			else
				pos = mid, start = mid + 1;
		}
		ans += pos+1;
	}

	cout << ans << endl;
	return 0;
}
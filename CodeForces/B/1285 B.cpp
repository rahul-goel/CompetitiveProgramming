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
	ll t;
	cin >> t;
	while(t--)
	{
		ll n, tot=0;
		cin >> n;
		vector < ll > arr;
		for(ll i=0, temp; i<n; i++)
		{
			cin >> temp;
			tot += temp;
			arr.push_back(temp);
		}
		ll mx = -1000000000000000, sum = 0;
		for(ll i=0; i<n-1; i++)
		{
			sum += arr[i];
			if(sum<0)
				sum = 0;
			mx = max(mx, sum);
		}
		sum = 0;
		for(ll i=1; i<n; i++)
		{
			sum += arr[i];
			if(sum<0)
				sum = 0;
			mx = max(mx, sum);
		}
		if(tot > mx)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}
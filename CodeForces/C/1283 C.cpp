//Created by Rahul Goel
#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>

using namespace std;
typedef long long ll;
ll mod = 1000000007;

int main()
{
	ll n;
	cin >> n;
	ll arr[200005]={0}, gift[200005] = {0};

	for(ll i=1; i<=n; i++)
	{
		cin >> arr[i];
		gift[arr[i]] = 1;
	}

	ll j=1, k=1, m = -1;
	while(j<=n)
	{
		while(arr[j] && j<=n)
			j++;
		if(j>n)
			break;
		if(arr[j]==0 && gift[j]==0)
		{
			//cout << j << endl;
			while(gift[k] && k<=n)
				k++;
			if(k>n)
			{
				k=1;
				while(gift[k] && k<=n)
					k++;
			}
			//cout << k << endl;
			if(k==j)
			{
				m = k++;
				while(gift[k] && k<=n)
				k++;
				if(k>n)
				{
					k=1;
					while(gift[k] && k<=n)
						k++;
				}
				arr[j] = k, gift[k] = 1, k = m;
			}
			else
				arr[j] = k, gift[k] = 1, k++;
		}
		j++;
	}

	j=1, k=1;
	while(j<=n)
	{
		while(arr[j] && j<=n)
			j++;
		while(gift[k] && k<=n)
			k++;
		if(j>n || k>n)
			break;
		arr[j] = k, gift[k] = 1;
	}
	for(ll i=1; i<=n; i++)
		cout << arr[i] << ' ';
	cout << endl;
	return 0;
}
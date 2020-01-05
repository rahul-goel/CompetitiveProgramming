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
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		int arr[200005];
		for(int i=0; i<n; i++)
			cin >> arr[i];
		int l=-1, r=-1;
		for(int i=0; i<n-1; i++)
		{
			if(abs(arr[i]-arr[i+1])>=2)
			{
				l=i, r=i+1;
				break;
			}
		}

		if(l!=-1 && r!=-1)
			cout << "YES" << endl << l+1 << ' ' << r+1 << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}
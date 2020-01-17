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
	int n, m, arr[300005] = {0}, flag = 0;
	vector < pair < int, int > > vec;
	cin >> n >> m;
	for(int i=0; i<m; i++)
	{
		int a, b;
		cin >> a >> b;
		vec.push_back(make_pair(a, b));
	}

	//let one of them be vec[0].first
	int x = vec[0].first, count = 0;
	for(int i=0; i<m; i++)
	{
		if(vec[i].first != x && vec[i].second != x)
			arr[vec[i].first]++, arr[vec[i].second]++, count++;
	}

	for(int i=1; i<=n; i++)
	{
		if(arr[i] == count)
		{
			cout << "YES" << endl;
			return 0;
		}
	}

	memset(arr, 0, sizeof(arr));
	count = 0, x = vec[0].second;
	for(int i=0; i<m; i++)
	{
		if(vec[i].first != x && vec[i].second != x)
			arr[vec[i].first]++, arr[vec[i].second]++, count++;			
	}

	for(int i=1; i<=n; i++)
	{
		if(arr[i] == count)
		{
			cout << "YES" << endl;
			return 0;
		}
	}

	cout << "NO" << endl;
	return 0;
}
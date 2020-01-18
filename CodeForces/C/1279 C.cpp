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
	int t;
	cin >> t;
	while(t--)
	{
		int n, m;
		cin >> n >> m;
		int stk[100005], gift[100005], pos[100005], arr = 1;
		for(int i=1; i<=n; i++)
		{
			cin >> stk[i];
			pos[stk[i]] = i;
		}
		for(int i=1; i<=m; i++)
			cin >> gift[i];
		ll time = 0;
		for(int i=1; i<=m; i++)
		{
			if(pos[gift[i]]<=arr)
				time += 1;
			else
				time += (pos[gift[i]] - i)*2 + 1, arr = pos[gift[i]];
			//cout << time << endl;
		}
		cout << time << endl;
	}	
	return 0;
}
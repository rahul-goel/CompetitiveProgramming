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
		int h, m;
		cin >> h >> m;
		int ans = (24-h-1)*60 + 60-m;
		cout << ans << endl;
	}
	return 0;
}
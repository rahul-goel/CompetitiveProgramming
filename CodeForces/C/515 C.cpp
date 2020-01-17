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
	ll n, num;
	cin >> n >> num;
	vector < char > ans;
	for(ll i=1; i<=n; i++)
	{
		ll k = num%10;
		if(k==2)
			ans.push_back(2 + '0');
		else if(k==3)
			ans.push_back(3 + '0');
		else if(k==4)
			ans.push_back(3 + '0'), ans.push_back(2 + '0'), ans.push_back(2 + '0');
		else if(k==5)
			ans.push_back(5 + '0');
		else if(k==6)
			ans.push_back(3 + '0'), ans.push_back(5 + '0');
		else if(k==7)
			ans.push_back(7 + '0');
		else if(k==8)
			ans.push_back(7 + '0'), ans.push_back(2 + '0'), ans.push_back(2 + '0'), ans.push_back(2 + '0');
		else if(k==9)
			ans.push_back(7 + '0'), ans.push_back(3 + '0'), ans.push_back(3 + '0'), ans.push_back(2 + '0');

		num/=10;
	}
	sort(ans.begin(), ans.end(), greater< char >());
	for(char c : ans)
		cout << c;
	cout << endl;
	return 0;
}

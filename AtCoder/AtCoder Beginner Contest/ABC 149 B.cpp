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
	ll a, b, k;
	cin >> a >> b >> k;
	if(a>=k)
	{
		a-=k;
		cout << a << ' ' << b <<endl;
	} 
	else
	{
		k-=a;
		cout << 0 << ' ' << max(0ll, b-k) << endl;
	}
	return 0;
}

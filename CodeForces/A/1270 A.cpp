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
		int n, k1, k2, m1=-1, m2=-1;
		cin >> n >> k1 >> k2;
		for(int i=0, temp; i<k1; i++)
		{
			cin >> temp;
			m1 = max(m1, temp);
		}
		for(int i=0, temp; i<k2; i++)
		{
			cin >> temp;
			m2 = max(m2, temp);
		}
		if(m1>m2)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}
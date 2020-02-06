/*
	Created by Rahul Goel.
*/

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
const int INF = 1000000000;

#define pii pair < int, int >
#define vi vector < int >
#define vvi vector < vector < int > >
#define vpii vector < pair < int, int > >
#define vvpii vector < vector < pair < int, int > > >
#define pb push_back
#define f first
#define s second
#define mp make_pair

bool compare(const pii &a, const pii &b)
{
	return ((a.f + a.s) < (b.f + b.s));
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		vpii vec;
		for(int i=0; i<n; i++)
		{
			int x, y;
			cin >> x >> y;
			vec.pb(mp(x, y));
		}
		sort(vec.begin(), vec.end(), compare);
		
		int x=0, y=0, flag = 1;
		vector < char > ans;
		for(auto gift : vec)
		{
			int gx = gift.f, gy = gift.s;
			if(gx>=x && gy >=y)
			{
				if(gx > x)
					for(int i=0; i<gx-x; i++)
						ans.pb('R');
				if(gy > y)
					for(int i=0; i<gy-y; i++)
						ans.pb('U');
				x=gx, y=gy;
			}
			else
			{
				flag = 0;
				break;
			}
		}
		if(flag)
		{
			cout << "YES" << endl;
			for(char c : ans)
				cout << c;
			cout << endl;
		}
		else
			cout << "NO" << endl;
	}
	return 0;
}
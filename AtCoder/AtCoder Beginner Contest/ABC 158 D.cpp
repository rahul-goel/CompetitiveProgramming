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

int main()
{
	string str;
	int q;
	bool reverse = false;
	cin >> str >> q;
	deque < char > dq;
	for(ll i=0, lim = str.length(); i < lim; i++)
		dq.pb(str[i]);
	while(q--)
	{
		int t;
		cin >> t;
		if(t==1)
		{
			reverse = !reverse;
		}
		else
		{
			int x;
			char c;
			cin >> x >> c;
			if(x == 1 && reverse)
				dq.pb(c);
			else if(x == 1 && !reverse)
				dq.push_front(c);
			else if(x == 2 && reverse)
				dq.push_front(c);
			else
				dq.pb(c);

		}
	}
	if(reverse)
	{
		while(!dq.empty())
		{
			cout << dq.back();
			dq.pop_back();
		}
		cout << endl;
	}
	else
	{
		while(!dq.empty())
		{
			cout << dq.front();
			dq.pop_front();
		}
		cout << endl;
	}
	return 0;
}

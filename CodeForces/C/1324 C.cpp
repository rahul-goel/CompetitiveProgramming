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
	int t;
	cin >> t;
	while(t--)
	{
		string st, str;
		cin >> st;
		str = "R" + st + "R";
		int len = str.length();
		int prev = 0, curr = 1;
		while(curr < len)
		{
			if(str[curr] == 'R')
				break;
			curr++;
		}
		int ans = curr-prev;
		while(curr < len)
		{
			if(str[curr] == 'R')
			{
				ans = max(ans, curr-prev);
				prev = curr;
			}
			curr++;
		}

		cout << ans << endl;
	}
	return 0;
}

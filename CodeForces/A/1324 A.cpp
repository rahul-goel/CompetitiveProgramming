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
		int n, odd = 0, even = 0;
		cin >> n;
		vi vec(n);
		for(int i=0; i<n; i++)
		{
			cin >> vec[i];
			if(vec[i]&1)
				odd++;
			else
				even++;
		}
		if(n == even || n == odd)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}	
	return 0;
}

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
#define ff first
#define ss second
#define mp make_pair

int main()
{
	int t;
	cin >> t;
	while(t--){
		int n, xu = 100000, xl = -100000, yu = 100000, yl = -100000;
		cin >> n;
		while(n--){
			int x, y, u, d, l, r;
			cin >> x >> y >> l >> u >> r >> d;
			if(u == 0 && yu > y)
				yu = y;
			if(d == 0 && yl < y)
				yl = y;
			if(r == 0 && xu > x)
				xu = x;
			if(l == 0 && xl < x)
				xl = x;
		}
		if(xu>=xl && yu>=yl)
			printf("%d %d %d\n", 1, xl, yl);
		else
			printf("0\n");
	}
	return 0;
}

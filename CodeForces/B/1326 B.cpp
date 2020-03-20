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
	int n, mx;
	cin >> n;
	vi a(n), b(n), x(n);
	for(int i=0; i<n; i++)
		cin >> b[i];
	mx = a[0] = b[0], x[0] = 0;

	for(int i=1; i<n; i++){
		x[i] = max(x[i-1], a[i-1]);
		a[i] = b[i] + x[i];
	}
	for(int u : a)
		cout << u << " ";
	cout << endl;
	return 0;
}

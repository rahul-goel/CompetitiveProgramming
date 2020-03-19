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
	ll a, b;
	cin >> a >> b;

	int pow2a = 0, pow3a = 0, pow5a = 0;
	int pow2b = 0, pow3b = 0, pow5b = 0;

	while(a%2==0)
		pow2a++, a/=2;
	while(a%3==0)
		pow3a++, a/=3;
	while(a%5==0)
		pow5a++, a/=5;
	while(b%2==0)
		pow2b++, b/=2;
	while(b%3==0)
		pow3b++, b/=3;
	while(b%5==0)
		pow5b++, b/=5;

	if(a == b)
		cout << abs(pow2a-pow2b) + abs(pow3a-pow3b) + abs(pow5a-pow5b) << endl;
	else
		cout<< -1 << endl;
	return 0;
}

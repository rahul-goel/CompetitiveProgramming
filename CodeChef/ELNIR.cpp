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
	string pi_str = "31415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679";
	string e_str =  "27182818284590452353602874713526624977572470936999595749669676277240766303535475945713821785251664274";
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		cout << pi_str[n-1]-'0'+e_str[n-1]-'0' << endl;
	}
	return 0;
}
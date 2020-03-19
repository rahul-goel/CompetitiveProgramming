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
	int a, b;
	cin >> a >> b;
	if(a<b){
		for(int i=0; i<b; i++)
			cout << a;
		cout << endl;
	}
	else{
		for(int i=0; i<a; i++)
			cout << b;
		cout << endl;
	}
	return 0;
}

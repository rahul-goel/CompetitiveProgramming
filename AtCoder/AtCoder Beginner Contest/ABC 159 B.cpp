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

bool check(string str){
	string str2 = str;
	reverse(str.begin(), str.end());
	if(str == str2)
		return true;
	else
		return false;
}

int main()
{
	string str;
	cin >> str;
	int n = str.length();
	string str1 = str.substr(0, n/2), str2 = str.substr((n+1)/2, n/2);
	if(check(str) && check(str1) && check(str2))
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	return 0;
}

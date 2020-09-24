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

vector < int > prefix_function(string str){
	int n = str.length();
	vector < int > pi(n, 0);
	for(int i=1; i<n; i++){
		int j = pi[i-1];
		while(j>0 && str[i] != str[j])
			j=pi[j-1];
		if(str[i] == str[j])
			j++;
		pi[i] = j;
	}
	return pi;
}

int main()
{
	string check, str;
	cin >> str >> check;
	string kmp = check + "#" + str;
	int n = check.length(), r = kmp.length();
	vi pi = prefix_function(kmp);
	for(int i=n*2; i<r; i++)
		if(pi[i] == n)
			cout << i-2*n << endl;
	return 0;
}

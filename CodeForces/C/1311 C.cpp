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
	while(t--){
		int n, m, asci[128] = {0};
		cin >> n >> m;
		string str;
		vi count(n, 0);

		cin >> str;
		for(int i=0; i<m; i++){
			int ind;
			cin >> ind;
			count[ind-1]++;
		}

		for(int i=n-2; i>=0; i--)
			count[i] += count[i+1];

		for(int i=0; i<n; i++)
			asci[str[i]] += count[i];
		for(char c : str)
			asci[c]++;

		for(int i='a'; i<='z'; i++)
			cout << asci[i] << " ";
		cout << endl;
	}
	return 0;
}

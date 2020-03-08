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
		int n;
		string str;
		cin >> n >> str;

		vector < string > vec(n+1);

		for(int i=1; i<=n; i++)
		{
			string temp;
			string str_new;
			str_new.resize(n-i+1);

			for(int j=0; j<i-1; j++)
				temp.pb(str[j]);

			if(!((n-i)&1))
				reverse(temp.begin(), temp.end());
			// cout << temp << endl;

			for(int j=0; j<n-i+1; j++)
				str_new[j] = str[j+i-1];
			
			str_new = str_new + temp;

			vec[i] = str_new;
			// cout << str_new << endl << endl;
		}

		string ans = str;
		int ans_k = 1;

		for(int i=1; i<=n; i++)
		{
			if(lexicographical_compare(vec[i].begin(), vec[i].end(), ans.begin(), ans.end()))
				ans = vec[i], ans_k = i; 
		}
		cout << ans << endl;
		cout << ans_k << endl;
	}
	return 0;
}
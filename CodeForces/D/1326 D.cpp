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

string prefix_function(string str){
	string str_rev = str;
	reverse(str_rev.begin(), str_rev.end());
	str = str + "#" + str_rev;

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
	
	int i = n-1, ans = pi[i];
	while(pi[i-1] > pi[i])
		ans = pi[i-1], i--;
	return str.substr(0, ans);
}

int main()
{
	int t;
	cin >> t;
	while(t--){
		string str;
		cin >> str;
		int len = str.length();
		
		string border, middle;
		int i=0, j=len-1;
		while(i<=j){
			if(str[i] == str[j]){
				border.pb(str[i]);
				i++, j--;
			}
			else
				break;
		}
		
		if(i<j){
			string str2 = str.substr(i, j-i+1);
			string mid1 = prefix_function(str2);
			reverse(str2.begin(), str2.end());
			string mid2 = prefix_function(str2);
			if(mid1.length() > mid2.length())
				middle = mid1;
			else
				middle = mid2;
		}
		else{
			cout << str << endl;
			continue;
		}
		
		string ans = border + middle;
		reverse(border.begin(), border.end());
		ans += border;
		cout << ans << endl;
	}
	return 0;
}

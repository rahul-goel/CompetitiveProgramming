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
	int n;
	cin >> n;
	int check[128] = {0};
	string ch = "helloworld";
	for(int i=0, lim=ch.length(); i<lim; i++)
		check[ch[i]]++;
	while(n--)
	{
		string str;
		cin >> str;
		int asci[128] = {0};
		for(int i=0, lim = str.length(); i<lim; i++)
			asci[str[i]]++;
		int flag = 1;
		for(int i='a'; i<='z'; i++)
		{
			if(asci[i] != check[i])
			{
				flag = 0;
				break;
			}
		}
		if(flag)
				cout << "Yes" << endl;
		else
			cout << "No" << endl;

	}
	return 0;
}
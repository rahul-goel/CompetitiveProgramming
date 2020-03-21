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

int main()
{
	int t;
	cin >> t;
	while(t--){
		int b, w, x;
		cin >> b >> w;
		int mx = max(w, b), mn = min(w, b);
		if(mx > 3*mn + 1){
			cout << "NO" << endl;
			continue;
		}

		cout << "YES" << endl;	
		if(b>w)
			x = 1;
		if(b==w){
			for(int i=3; i<3+w+b; i++)
				printf("3 %d\n", i);
		}
		else if(b>w){
			int lim = 3+w+w;
			for(int i=2; i<=2+w+w; i+=2)
				printf("3 %d\n", i);
			for(int i=3; i<3+w+w; i+=2)
				printf("3 %d\n", i);
			int i;
			b -= w+1, w = 0, i = 3;
			while(b>0 && i<lim)
				printf("2 %d\n", i), i+=2, b--;
			i = 3;
			while(b>0 && i<lim)
				printf("4 %d\n", i), i+=2, b--;
		}
		else{
			int lim = 4+b+b;
			for(int i=3; i<=3+b+b; i+=2)
				printf("3 %d\n", i);
			for(int i=4; i<4+b+b; i+=2)
				printf("3 %d\n", i);
			int i;
			w -= b+1, b = 0, i = 4;
			while(w>0 && i<lim)
				printf("2 %d\n", i), i+=2, w--;
			i = 4;
			while(w>0 && i<lim)
				printf("4 %d\n", i), i+=2, w--;
		}
	}
	return 0;
}

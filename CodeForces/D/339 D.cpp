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

int MAX_N;
vi t, a;

// Getting true from children means that OR the children, false means XOR the children

bool build(int v, int tl, int tr){
	if(tl == tr){
		t[v] = a[tl];
		return true;
	}
	else{
		int tm = (tr + tl)/2;
		bool what_to_do;

		//these two are gonna be the same
		what_to_do = build(2*v, tl, tm);
		what_to_do = build(2*v + 1, tm + 1, tr);
		
		if(what_to_do)
			t[v] = t[2*v] | t[2*v + 1];
		else
			t[v] = t[2*v] ^ t[2*v + 1];

		return !what_to_do;
	}
}

bool update(int v, int tl, int tr, int pos, int new_val){
	if(tl == tr){
		t[v] = new_val;
		return true;
	}
	else{
		int tm = (tl + tr)/2;
		bool what_to_do;
		if(pos <= tm)
			what_to_do = update(2*v, tl, tm, pos, new_val);
		else
			what_to_do = update(2*v + 1, tm + 1, tr, pos, new_val);

		if(what_to_do)
			t[v] = t[2*v] | t[2*v + 1];
		else
			t[v] = t[2*v] ^ t[2*v + 1];
		
		return !what_to_do;
	}
}

int main()
{
	int n, q;
	cin >> n >> q;
	MAX_N = (ll)pow(2, n);
	t.resize(4*MAX_N), a.resize(MAX_N);
	for(int i=0; i<MAX_N; i++)
		cin >> a[i];

	build(1, 0, MAX_N-1);
	while(q--){
		int pos, new_val;
		cin >> pos >> new_val;
		update(1, 0, MAX_N-1, pos-1, new_val);
		cout << t[1] << endl;
	}
	return 0;
}

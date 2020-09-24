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
vi t(4*MAX_N), a(MAX_N);

void build(int v, int tl, int tr){
	if(tl == tr){
		t[v] = a[tl];
	}
	else{
		int tm = (tr + tl)/2;
		build(2*v, tl, tm);
		build(2*v + 1, tm + 1, tr);
		t[v] = t[2*v] + t[2*v + 1];
	}
}

int sum(int v, int tl, int tr, int l, int r){
	if(l > r)
		return 0;
	if(l==tl && r==tr)
		return t[v];
	int tm = (tl + tr)/2;
	return sum(2*v, tl, tm, l, min(r, tm)) + sum(2*v + 1, tm + 1, tr, max(l, tm + 1), r);
}

void update(int v, int tl, int tr, int pos, int new_val){
	if(tl == tr){
		t[v] = new_val;
	}
	else{
		int tm = (tl + tr)/2;
		if(pos <= tm)
			update(2*v, tl, tm, pos, new_val);
		else
			update(2*v + 1, tm + 1, tr, pos, new_val);
		t[v] = t[2*v] + t[2*v + 1];
	}
}

int main()
{

	return 0;
}

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
vector < bool > marked(4*MAX_N);

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

void push(int v){
	if(marked[v]){
		t[2*v] = t[2*v + 1] = t[v];
		marked[2*v] = marked[2*v + 1] = true;
		marked[v] = false;
	}
}

void update(int v, int tl, int tr, int l, int r, int new_val){
	if(l > r)
		return;
	if(l == tl && tr == r){
		t[v] = new_val;
		marked[v] = true;
	}
	else{
		push(v);
		int tm = (tl + tr)/2;
		update(2*v, tl, tm, l, min(tm, r), new_val);
		update(2*v + 1, tm + 1, tr, max(tm + 1, l), r, new_val);
	}
}

int get(int v, int tl, int tr, int pos){
	if(tl == tr){
		return a[v];
	}
	push(v);
	int tm = (tl + tr)/2;
	if(pos <= tm)
		return get(2*v, tl, tm, pos);
	else
		return get(2*v + 1, tm + 1, tr, pos);
}

int main()
{

	return 0;
}

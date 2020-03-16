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

vvi adj;
vpii edges;
vi ans;

void add_edge(int from, int to){
	adj[from].pb(to), adj[to].pb(from);
}

int main()
{
	int n;
	cin >> n;
	adj.resize(n+1), ans.resize(n-1, -1);

	for(int i=0; i<n-1; i++){
		int from, to;
		cin >> from >> to;
		add_edge(from, to);
		edges.pb({from, to});
	}

	int ptr = 0, node = -1;

	for(auto ed : edges){
		int u = ed.f, v = ed.s;
		if(adj[u].size() >= 3){
			node = u;
			break;
		}
		else if(adj[v].size() >= 3){
			node = v;
			break;
		}
		ptr++;
	}
	if(node == -1){
		for(int i=0; i<n-1; i++)
			cout << i << endl;
	}
	else{
		int p1, p2, p3, change = 0, cur = 3;
		p1 = adj[node][0], p2 = adj[node][1], p3 = adj[node][2];
		for(auto ed : edges){
			int u = ed.f, v = ed.s;
			if(u == node){
				if(v == p1)
					cout << change++ << endl;
				else if(v == p2)
					cout << change++ << endl;
				else if(v == p3)
					cout << change++ << endl;
				else
					cout << cur++ << endl;
			}
			else if(v == node){
				if(u == p1)
					cout << change++ << endl;
				else if(u == p2)
					cout << change++ << endl;
				else if(u == p3)
					cout << change++ << endl;
				else
					cout << cur++ << endl;
			}
			else
				cout << cur++ << endl;
		}
	}
	return 0;
}

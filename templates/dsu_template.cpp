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


struct DSU {
	vector<int> parent, size;

	DSU (int n) {
		parent.resize(n);
		size.resize(n);
		for (int i = 0; i < n; i++) make_set(i);
	}

	void make_set(int v){
		parent[v] = v;
		size[v] = 1;
	}

	int find_set(int v){
		if(v == parent[v])
			return v;
		return parent[v] = find_set(parent[v]);
	}

	void union_sets(int a, int b){
		a = find_set(a), b = find_set(b);
		if(a != b){
			if(size[a] < size[b])
				swap(a, b);
			parent[b] = a, size[a] += size[b];
		}
	}
};

int main(){

	return 0;
}

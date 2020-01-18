//Created by Rahul Goel
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

vector < int > parent, size;

void make_set(int v)
{
	parent[v] = v;
	size[v] = 1;
}

int find_set(int v)
{
	if(v == parent[v])
		return v;
	return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b)
{
	a = find_set(a), b = find_set(b);

	if(a != b)
	{
		if(size[a] < size[b])
			swap(a, b);
		
		parent[b] = a, size[a] += size[b];
	}
}

int main()
{
	int n, m, count0lang = 0;
	cin >> n >> m;
	parent.resize(m+n+5, 0), size.resize(m+n+5, 0);
	for(int i=1+m; i<=n+m; i++)
	{
		make_set(i);
		int k;
		cin >> k;
		if(k==0)
			count0lang++;
		for(int j=0; j<k; j++)
		{
			int lang;
			cin >> lang;
			if(!size[lang])
				make_set(lang);
			union_sets(lang, i);
		}
	}

	vector < int > check(m+n+5, 0);
	int count = 0;
	for(int i=1; i<=m+n; i++)
	{
		int p = find_set(i);
		if(!check[p] && p!=0)
			check[p] = 1, count++;
	}
	

	if(count0lang==n)
		cout << n << endl;
	else
		cout << count - 1 << endl;
	return 0;
}
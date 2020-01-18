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
	if(parent[v] == v)
		return v;
	return parent[v] = find_set(parent[v]);
}

int union_sets(int a, int b)
{
	a = find_set(a), b = find_set(b);
	if(a!=b)
	{
		if(size[a]<size[b])
			swap(a, b);
		parent[b] = a, size[a] += size[b];
	}

}

int main()
{
	parent.resize(30), size.resize(30, 0);
	int n;
	string s, t;
	cin >> n >> s >> t;
	for(int i=0; i<n; i++)
		s[i] -= 'a', t[i] -= 'a';
	for(int i=0; i<n; i++)
	{
		if(s[i]!=t[i])
		{
			if(!size[s[i]])
				make_set(s[i]);
			if(!size[t[i]]) 
				make_set(t[i]);

			union_sets(s[i], t[i]);
		}
	}
	int count = 0;
	vector < vector < int > > ans(30);
	for(int i=0; i<26; i++)
	{
		if(size[i])
		{
			int p = find_set(i);
			if(p!=i)
				ans[p].push_back(i), count++;
		}
	}

	cout << count << endl;
	for(int i=0; i<26; i++)
	{
		if(ans[i].size())
		{
			for(int u : ans[i])
				printf("%c %c\n", i+'a', u+'a');
		}
	}
	return 0;
}
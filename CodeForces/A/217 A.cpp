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
	int n;
	cin >> n;
	parent.resize(3005, 0), size.resize(3005, 0);
	for(int i=0; i<n; i++)
	{
		int x, y;
		cin >> x >> y;
		y = y + 2000;//representing y axises as some other number.
		if(!size[x])
			make_set(x);
		if(!size[y])
			make_set(y);
		union_sets(x, y);
	}
	vector < int > check(3005, 0);
	int count = 0;
	for(int i=1; i<=1000; i++)
	{
		int p = find_set(i);
		if(!check[p] && p!=0)
			check[p] = 1, count++;
	}
	//cout << count << endl;
	for(int i=2001; i<=3000; i++)
	{
		int p = find_set(i);
		if(!check[p] && p!=0)
			check[p] = 1, count++;
	}
	//cout << parent[2] << parent[4] << parent[2001] << endl;
	cout << count - 1 << endl;
	return 0;
}
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

int main()
{
	int n;
	cin >> n;
	vector < int > time;
	for(int i=0; i<n; i++)
	{
		int h, m;
		cin >> h >> m;
		time.push_back(h*60 + m);
	}
	sort(time.begin(), time.end());
	// for(int u : time)
	// 	cout << u << ' ';
	// cout << endl;
	int count = 1, ptr = 0;
	while(ptr<time.size())
	{
		int c = 1;
		while(time[ptr]==time[ptr+1] && ptr<time.size()-1)
			ptr++, c++;
		count = max(c, count);
		ptr++;
	}
	cout << count << endl;
	return 0;
}
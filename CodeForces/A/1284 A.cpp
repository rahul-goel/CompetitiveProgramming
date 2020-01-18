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
	int n, m;
	cin >> n >> m;
	string str1[25], str2[25];
	for(int i=0; i<n; i++)
		cin >> str1[i];
	for(int i=0; i<m; i++)
		cin >> str2[i];
	int q;
	cin >> q;
	while(q--)
	{
		int y;
		cin >> y;
		cout << str1[(y-1)%n] << str2[(y-1)%m] << endl;
	}
	return 0;
}
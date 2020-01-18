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
	string str;
	cin >> str;
	int c1=0, c2=0;
	for(int i=0; i<n; i++)
	{
		if(str[i]=='L')
			c1++;
		else
			c2++;
	}
	cout << c1+c2+1 << endl;
	return 0;
}
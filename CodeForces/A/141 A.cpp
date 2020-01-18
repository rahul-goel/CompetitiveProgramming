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
	string a, b, c;
	cin >> a >> b >> c;
	int asci1[128]={0}, asci2[128]={0};
	for(char x : a)
		asci1[x]++;
	for(char x : b)
		asci1[x]++;
	for(char x : c)
		asci2[x]++;

	int flag = 1;
	for(int i=0; i<128; i++)
	{
		if(asci1[i]!=asci2[i])
		{
			flag = 0;
			break;
		}
	}
	if(flag)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}
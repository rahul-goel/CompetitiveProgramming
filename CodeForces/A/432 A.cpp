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
	int n, k;
	cin >> n >> k;
	vector < int > arr;
	for(int i=0; i<n; i++)
	{
		int temp;
		cin >> temp;
		arr.push_back(temp);
	}
	sort(arr.begin(), arr.end());
	int start = 0, end = arr.size()-1, mid, pos = -1;
	while(start<=end)
	{
		mid = (start+end)/2;
		if(arr[mid]>5-k)
			end = mid-1;
		else
			pos = mid, start = mid+1;
	}
	if(pos == -1)
		cout << 0 << endl;
	else
		cout << (pos+1)/3 << endl;
	return 0;
}
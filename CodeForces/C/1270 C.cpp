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
	int t;
	cin >> t;
	while(t--)
	{
		ll n, arr[100005], x = 0, sum = 0, a=0;
		cin >> n;
		for(ll i=0; i<n; i++)
		{
			cin >> arr[i]; 
			x ^= arr[i], sum += arr[i];
		}
		//cout << 's' << ' ' << sum << ' ' << 2*x << endl;
		if(2*x == sum)
			cout << 0 << endl << endl;
		else if(2*x > sum && (2*x - sum)%2==0)
		{
			a = (2*x - sum)/2;
			x^=a, x^=a, sum+=a*2;
			cout << 2 << endl << a << ' ' << a << endl;
		}
		else if(2*x > sum && (2*x - sum)%2==1)
		{

			x^=(ll)(pow(2, 50)+1), sum += (ll)(pow(2, 50)+1);
			//cout << 's' << ' ' << sum << ' ' << 2*x << ' ' << 2*x - sum << endl;
			if(2*x == sum)
				cout << 1 << endl << (ll)(pow(2, 50)+1) << endl;
			else if(2*x > sum && (2*x - sum)%2==0)
			{
				a = (2*x - sum)/2;
				x^=a, x^=a, sum+=a*2;
				cout << 3 << endl << (ll)(pow(2, 50)+1) << ' ' << a << ' ' << a << endl;
			}
		}
		else if(sum > 2*x && (sum - 2*x)%2==0)
		{
			x^= (ll)pow(2, 50), sum += (ll)pow(2, 50);
			if(2*x == sum)
				cout << 1 << endl << (ll)pow(2, 50) << endl;
			else if(2*x > sum && (2*x - sum)%2==0)
			{
				a = (2*x - sum)/2;
				x^=a, x^=a, sum+=a*2;
				cout << 3 << endl << (ll)pow(2, 50) << ' ' << a << ' ' << a << endl;
			}
		}
		else if(sum > 2*x && (sum - 2*x)%2==1)
		{
			x^= (ll)(pow(2, 50)+1), sum += (ll)(pow(2, 50)+1);
			if(2*x == sum)
				cout << 1 << endl << (ll)(pow(2, 50)+1) << endl;
			else if(2*x > sum && (2*x - sum)%2==0)
			{
				a = (2*x - sum)/2;
				x^=a, x^=a, sum+=a*2;
				cout << 3 << endl << (ll)(pow(2, 50)+1) << ' ' << a << ' ' << a<< endl;
			}
		}
		//cout << 'c' << ' ' << x*2 << ' ' << sum << endl;
	}
	return 0;
}
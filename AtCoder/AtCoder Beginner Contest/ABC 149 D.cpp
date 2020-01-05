#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>

using namespace std;
typedef long long ll;
ll mod = 1000000007;

int main()
{
	int n, k, r, s, p;
	cin >> n >> k >> r >> s >> p;
	string t;
	cin >> t;
	int ans = 0, flag = 0;

	if(r>=s && r>=p)
	{
		flag = 0;
		for(int i=0; i<k; i++)
		{
			flag = 0;
			for(int j=i; j<n; j+=k)
			{
				if(t[j] == 's' && flag == 0)
					ans += r, flag = 1;
				else if(t[j] ==  's' && flag == 1)
					flag = 0;
				else
					flag = 0;
			}
		}

		if(s == max(s, p))
		{
			flag = 0;
			for(int i=0; i<k; i++)
			{
				flag = 0;
				for(int j=i; j<n; j+=k)
				{
					if(t[j] == 'p' && flag == 0)
						ans += s, flag = 1;
					else if(t[j] ==  'p' && flag == 1)
						flag = 0;
					else
						flag = 0;
				}
			}
			
			flag = 0;
			for(int i=0; i<k; i++)
			{
				flag = 0;
				for(int j=i; j<n; j+=k)
				{
					if(t[j] == 'r' && flag == 0)
						ans += p, flag = 1;
					else if(t[j] ==  'r' && flag == 1)
						flag = 0;
					else
						flag = 0;
				}
			}
		}
		else if(p == max(s, p))
		{
			flag = 0;
			for(int i=0; i<k; i++)
			{
				flag = 0;
				for(int j=i; j<n; j+=k)
				{
					if(t[j] == 'r' && flag == 0)
						ans += p, flag = 1;
					else if(t[j] ==  'r' && flag == 1)
						flag = 0;
					else
						flag = 0;
				}
			}
			flag = 0;
			for(int i=0; i<k; i++)
			{
				flag = 0;
				for(int j=i; j<n; j+=k)
				{
					if(t[j] == 'p' && flag == 0)
						ans += s, flag = 1;
					else if(t[j] ==  'p' && flag == 1)
						flag = 0;
					else
						flag = 0;
				}
			}
		}
	}

	else if(s>=p && s>=r)
	{
		flag = 0;
		for(int i=0; i<k; i++)
		{
			flag = 0;
			for(int j=i; j<n; j+=k)
			{
				if(t[j] == 'p' && flag == 0)
					ans += s, flag = 1;
				else if(t[j] ==  'p' && flag == 1)
					flag = 0;
				else
					flag = 0;
			}
		}

		if(r == max(r, p))
		{
			flag = 0;
			for(int i=0; i<k; i++)
			{
				flag = 0;
				for(int j=i; j<n; j+=k)
				{
					if(t[j] == 's' && flag == 0)
						ans += r, flag = 1;
					else if(t[j] ==  's' && flag == 1)
						flag = 0;
					else
						flag = 0;
				}

			}
			flag = 0;
			for(int i=0; i<k; i++)
			{
				flag = 0;
				for(int j=i; j<n; j+=k)
				{
					if(t[j] == 'r' && flag == 0)
						ans += p, flag = 1;
					else if(t[j] ==  'r' && flag == 1)
						flag = 0;
					else
						flag = 0;
				}
			}
		}
		else if(p == max(r, p))
		{
			flag = 0;
			for(int i=0; i<k; i++)
			{
				flag = 0;
				for(int j=i; j<n; j+=k)
				{
					if(t[j] == 'r' && flag == 0)
						ans += p, flag = 1;
					else if(t[j] ==  'r' && flag == 1)
						flag = 0;
					else
						flag = 0;
				}
			}
			flag = 0;
			for(int i=0; i<k; i++)
			{
				flag = 0;
				for(int j=i; j<n; j+=k)
				{
					if(t[j] == 's' && flag == 0)
						ans += r, flag = 1;
					else if(t[j] ==  's' && flag == 1)
						flag = 0;
					else
						flag = 0;
				}
			}
		}
	}

	else if(p>=s && p>=r)
	{
		flag = 0;
		for(int i=0; i<k; i++)
		{
			flag = 0;
			for(int j=i; j<n; j+=k)
			{
				if(t[j] == 'r' && flag == 0)
					ans += p, flag = 1;
				else if(t[j] ==  'r' && flag == 1)
					flag = 0;
				else
					flag = 0;
			}
		}

		if(s == max(s, r))
		{
			flag = 0;
			for(int i=0; i<k; i++)
			{
				flag = 0;
				for(int j=i; j<n; j+=k)
				{
					if(t[j] == 'p' && flag == 0)
						ans += s, flag = 1;
					else if(t[j] ==  'p' && flag == 1)
						flag = 0;
					else
						flag = 0;
				}
			}
			flag = 0;
			for(int i=0; i<k; i++)
			{
				flag = 0;
				for(int j=i; j<n; j+=k)
				{
					if(t[j] == 's' && flag == 0)
						ans += r, flag = 1;
					else if(t[j] ==  's' && flag == 1)
						flag = 0;
					else
						flag = 0;
				}
			}
		}
		else if(r == max(s, r))
		{
			flag = 0;
			for(int i=0; i<k; i++)
			{
				flag = 0;
				for(int j=i; j<n; j+=k)
				{
					if(t[j] == 's' && flag == 0)
						ans += r, flag = 1;
					else if(t[j] ==  's' && flag == 1)
						flag = 0;
					else
						flag = 0;
				}
			}
			flag = 0;
			for(int i=0; i<k; i++)
			{
				flag = 0;
				for(int j=i; j<n; j+=k)
				{
					if(t[j] == 'p' && flag == 0)
						ans += s, flag = 1;
					else if(t[j] ==  'p' && flag == 1)
						flag = 0;
					else
						flag = 0;
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}
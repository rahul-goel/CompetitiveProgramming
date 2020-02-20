/*
	Created by Rahul Goel.
*/

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
const int INF = 1000000000;

#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vpii vector<pair<int, int>>
#define vvpii vector<vector<pair<int, int>>>
#define pb push_back
#define f first
#define s second
#define mp make_pair

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int count_odd = 0, count_even = 0;
        for (int i = 0; i < n; i++)
        {
            int temp;
            cin >> temp;
            if (temp & 1)
                count_odd++;
            else
                count_even++;
        }
        if (count_even && count_odd)
            cout << "YES" << endl;
        else if (count_odd & 1)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
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

#define pii pair < int, int >
#define vi vector < int >
#define vvi vector < vector < int > >
#define vpii vector < pair < int, int > >
#define vvpii vector < vector < pair < int, int > > >
#define pb push_back
#define f first
#define s second
#define mp make_pair

int main(){
    ll xorr, sum;
    cin >> xorr >> sum;
    if((xorr > sum) || (xorr-sum)&1)
        cout << -1 << endl;
    else if(xorr == 0 && sum == 0)
        cout << 0 << endl;
    else if(sum == xorr)
        cout << 1 << endl << xorr << endl;
    else if(!(((sum - xorr)/2) & xorr))
        cout << 2 << endl << ((sum-xorr)/2) << " " << ((sum+xorr)/2) << endl;
    else
        cout << 3 << endl << xorr << " " << (sum-xorr)/2 << " " << (sum-xorr)/2 << endl;
    return 0;
}

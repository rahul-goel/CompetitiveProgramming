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
const ll INF = 1000000000;

#define pii pair < ll, ll >
#define vi vector < ll >
#define vvi vector < vector < ll > >
#define vpii vector < pair < ll, ll > >
#define vvpii vector < vector < pair < ll, ll > > >
#define pb push_back
#define f first
#define s second
#define mp make_pair

int main(){
    ll t;
    cin >> t;
    while(t--){
        ll n, m;
        cin >> n >> m;
        ll mx = m, mn = m, prev = 0;

        bool flag = true;
        while(n--){
            ll low, up, k;
            cin >> k >> low >> up;

            mx += k - prev;
            mn -= k - prev;

            if(mx < low || mn > up){
                flag = flag && false;
            }
            mx = min(mx, up);
            mn = max(mn, low);
            prev = k;
        }

        if(flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}

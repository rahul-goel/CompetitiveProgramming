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
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll mod = 1000000007;
const int INF = 1e9;
const ll LINF = 1e18;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(c) (c).begin(), (c).end()
#define pii pair < ll, ll >
#define vi vector < ll >
#define vb vector < bool >
#define vvi vector < vector < ll > >
#define vvb vector < vector < bool > >
#define vpii vector < pair < ll, ll > >
#define vvpii vector < vector < pair < ll, ll > > >
#define pb push_back
#define f first
#define s second
#define mp make_pair

long double pr = 1e-6;

long double dist(long double x1, long double y1, long double x2, long double y2){
    long double ans = sqrtl(powl(x1-x2, 2) + powl(y1-y2, 2)); 
    return ans;
}

ll solve(){
    long double R, x1, y1, x2, y2;
    cin >> R >> x1 >> y1 >> x2 >> y2;
   
    cout << fixed << setprecision(15);

    if(dist(x1, y1, x2, y2) > R){
        cout << x1 << " " << y1 << " " << R << endl;
        return 0;
    }
    
    if(dist(x1, y1, x2, y2) <= pr){
       cout << x1 + R/2 << " " << y1 << " " << R/2 << endl; 
       return 0;
    }

    long double r_new = (R + dist(x1, y1, x2, y2)) / 2;
    cout << x2 + r_new*(x1-x2)/dist(x1, y1, x2, y2) << " " << y2 + r_new*(y1-y2)/dist(x1, y1, x2, y2) << " " << r_new << endl;

    return 0;
}

int main(){
    fastio;

    ll t = 1;
    while(t--)
        solve();

    return 0;
}

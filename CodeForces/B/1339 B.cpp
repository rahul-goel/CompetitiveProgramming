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

using namespace std;
typedef long long ll;
ll mod = 1000000007;
const int INF = 1e9;
const ll LINF = 1e18;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(c) (c).begin(), (c).end()
#define pii pair < int, int >
#define vi vector < int >
#define vb vector < bool >
#define vvi vector < vector < int > >
#define vvb vector < vector < bool > >
#define vpii vector < pair < int, int > >
#define vvpii vector < vector < pair < int, int > > >
#define pb push_back
#define f first
#define s second
#define mp make_pair

int main(){
    fastio;
    
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        vi vec(n);
        for(ll i=0; i<n; i++)
            cin >> vec[i];
        sort(all(vec), greater<ll>());
        deque < ll > dq;
        for(ll u : vec)
            dq.pb(u);
        vec.clear(); 
        while(!dq.empty()){
            if(!dq.empty())
                vec.pb(dq.back()), dq.pop_back();
            if(!dq.empty())
                vec.pb(dq.front()), dq.pop_front();
        }
        reverse(all(vec));
        for(ll u : vec)
            cout << u<< " ";
        cout << endl; 
    }

    return 0;
}

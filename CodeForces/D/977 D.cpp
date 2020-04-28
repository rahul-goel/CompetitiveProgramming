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

ll solve(){
    ll n;
    cin >> n;
    vi vec(n), next(n);
    map < ll, ll > mapper;
    ll ptr = 1;
    for(ll i=0; i<n; i++){
        cin >> vec[i];
        mapper[vec[i]] = ptr++;
    }
    
    deque < ll > dq;
    dq.push_front(vec[0]);
    while(dq.size() != n){
        if(mapper[dq.front() * 2])
            dq.push_front(dq.front() * 2);
        else if(dq.front()%3==0 && mapper[dq.front()/3])
            dq.push_front(dq.front()/3);
        else if(mapper[dq.back()*3])
            dq.push_back(dq.back()*3);
        else if(dq.back()%2==0 && mapper[dq.back()/2])
            dq.push_back(dq.back()/2);
    }

    while(!dq.empty())
        cout << dq.back() << " ", dq.pop_back();
    cout << endl;
    
    return 0;
}

int main(){
    fastio;

    ll t = 1;
    while(t--)
        solve();

    return 0;
}

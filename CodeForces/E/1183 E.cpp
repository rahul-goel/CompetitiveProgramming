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
#define present(c,x) ((c).find(x) != (c).end())//for sets,maps,multimaps
#define cpresent(c,x) (find(all(c),x) != (c).end())//for vectors
#define min_pq(t) priority_queue < t, vector < t >, greater < t > >
#define max_pq(t) priority_queue < t >
#define pb push_back
#define ff first
#define ss second

ll mod_sum() { return 0ll; }
template<typename T, typename... Args>
T mod_sum(T a, Args... args) { return ((a + mod_sum(args...))%mod + mod)%mod; }

ll mod_prod() { return 1ll; }
template<typename T, typename... Args>
T mod_product(T a, Args... args) { return (a*mod_product(args...))%mod; }

// --------------------------------------------------------------

ll solve(){
    ll n, k;
    cin >> n >> k;
    string str;
    cin >> str;
    
    if(k == 1){
        cout << 0 << endl;
        return 0;
    }

    unordered_set < string > visited;
    queue < string > q;
    ll cost = n*k;
    q.push(str), k--, visited.insert(str), cost -= str.size();
    while(!q.empty()){
        string popper = q.front();
        q.pop();
        for(ll i=0; i < (ll)popper.size(); i++){
            string next = popper.substr(0, i) + popper.substr(i+1, popper.size() - i - 1);
            if(!present(visited, next))
                cost -= next.size(), q.push(next), k--, visited.insert(next);
            if(k == 0)
                break;
        }
        if(k == 0)
            break;
    }

    if(k)
        cout << -1 << endl;
    else
        cout << cost << endl;

    return 0;
}

int main(){
    fastio;

    ll t = 1;
    while(t--)
        solve();

    return 0;
}


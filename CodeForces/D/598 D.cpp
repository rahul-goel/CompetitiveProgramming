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

#define fastio          ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(c)          (c).begin(), (c).end()
#define pii             pair < ll, ll >
#define vi              vector < ll >
#define vb              vector < bool >
#define vvi             vector < vector < ll > >
#define vvb             vector < vector < bool > >
#define vpii            vector < pair < ll, ll > >
#define vvpii           vector < vector < pair < ll, ll > > >
#define present(c,x)    ((c).find(x) != (c).end())
#define cpresent(c,x)   (find(all(c),x) != (c).end())
#define min_pq(t)       priority_queue < t, vector < t >, greater < t > >
#define max_pq(t)       priority_queue < t >
#define pb              push_back
#define ff              first
#define ss              second

ll mod_sum() { return 0ll; }
template<typename T, typename... Args>
T mod_sum(T a, Args... args) { return ((a + mod_sum(args...))%mod + mod)%mod; }

ll mod_prod() { return 1ll; }
template<typename T, typename... Args>
T mod_product(T a, Args... args) { return (a*mod_product(args...))%mod; }

/*
   Code begins after this.
*/

vector < vector < char > > mat;
vvb vis;

vector < ll > parent, szzz, cnt;

ll hsh(ll r, ll c, ll m){
    return r*m + c;
}

void make_set(ll v, ll c){
    parent[v] = v;
    szzz[v] = 1;
    cnt[v] = c;
}

ll find_set(ll v){
    if(v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(ll a, ll b){
    a = find_set(a), b = find_set(b);
    if(a != b){
        if(szzz[a] < szzz[b])
            swap(a, b);
        parent[b] = a, szzz[a] += szzz[b], cnt[a] += cnt[b];
    }
}

ll solve(){
    ll n, m, k;
    cin >> n >> m >> k;
    mat.resize(n, vector <char>(m));
    vis.resize(n, vb(n, false));
    parent.resize(n*m), szzz.resize(n*m), cnt.resize(n*m);


    for(ll i=0; i<n; i++){
        for(ll j=0; j<m; j++){
            cin >> mat[i][j];
        }
    }

    for(ll i=0; i<n; i++){
        for(ll j=0; j<m; j++){
            if(mat[i][j] == '.'){
                ll c =0;
                c += (mat[i-1][j] == '*');
                c += (mat[i+1][j] == '*');
                c += (mat[i][j-1] == '*');
                c += (mat[i][j+1] == '*');
                make_set(hsh(i, j, m), c);
            }
        }
    }

    for(ll i=0; i<n; i++){
        for(ll j=0; j<m; j++){
            if(mat[i][j] == '.'){
                if(mat[i-1][j] == '.')
                    union_sets(hsh(i, j, m), hsh(i-1, j, m));
                if(mat[i+1][j] == '.')
                    union_sets(hsh(i, j, m), hsh(i+1, j, m));
                if(mat[i][j-1] == '.')
                    union_sets(hsh(i, j, m), hsh(i, j-1, m));
                if(mat[i][j+1] == '.')
                    union_sets(hsh(i, j, m), hsh(i, j+1, m));
            }
        }
    }

    while(k--){
        ll i, j;
        cin >> i >> j;
        i--, j--;
        cout << cnt[find_set(hsh(i, j, m))] << endl;
    }

    return 0;
}


int main(){
    fastio;

    ll t = 1;
    while(t--)
        solve();

    return 0;
}


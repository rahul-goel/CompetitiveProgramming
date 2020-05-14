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
#define aint(c)          (c).begin(), (c).end()
#define pii             pair < int, int >
#define vi              vector < int >
#define vb              vector < bool >
#define vvi             vector < vector < int > >
#define vvb             vector < vector < bool > >
#define vpii            vector < pair < int, int > >
#define vvpii           vector < vector < pair < int, int > > >
#define present(c,x)    ((c).find(x) != (c).end())
#define cpresent(c,x)   (find(aint(c),x) != (c).end())
#define min_pq(t)       priority_queue < t, vector < t >, greater < t > >
#define max_pq(t)       priority_queue < t >
#define pb              push_back
#define ff              first
#define ss              second

int mod_sum() { return 0; }
template<typename T, typename... Args>
T mod_sum(T a, Args... args) { return ((a + mod_sum(args...))%mod + mod)%mod; }

int mod_prod() { return 1; }
template<typename T, typename... Args>
T mod_product(T a, Args... args) { return (a*mod_product(args...))%mod; }

/*
    Code begins after this.
*/


int solve(){
    int n, k;
    cin >> n >> k;
    string str;
    cin >> str;
    
    int sum = 0;
    for(int i=0; i<n; i++)
        sum += (str[i]=='1');
    int ans = sum;
    for(int i=0; i<k; i++){
        int dif = 0;
        for(int j=i; j<n; j+=k){
            if(str[j] == '1')
                dif++;
            else
                dif--;
            dif = max(dif, 0);
            ans = min(ans, sum-dif);
        }
    }
    
    
    cout << ans << '\n';

    return 0;
}


int main(){
    fastio;

    int t = 1;
    cin >> t;
    while(t--)
        solve();

    return 0;
}


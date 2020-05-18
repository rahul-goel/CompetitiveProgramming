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


ll solve(){
    string str;
    cin >> str;
    bool flag = true;
    ll l=0, r=str.size()-1;
    ll asci[128] = {0};
    asci['A']++, asci['H']++, asci['I']++, asci['M']++, asci['O']++, asci['T']++, asci['U']++, asci['V']++, asci['W']++, asci['X']++, asci['Y']++;
    asci['b']++, asci['d']++, asci['o']++, asci['v']++, asci['w']++, asci['x']++, asci['p']++, asci['q']++;

    for(char x : str)
        if(asci[x] == 0)
            flag = false;

    if(flag == false){
        cout << "NIE" << endl;
        return 0;
     }


    while(l<=r){
        if(str[l]=='b' && str[r]=='d')
            l++, r--;
        else if(str[l]=='d' && str[r]=='b')
            l++, r--;
        else if(str[l]=='b' || str[r]=='d')
            flag = false, l++, r--;
        else if(str[l]=='p' && str[r]=='q')
            l++, r--;
        else if(str[l]=='q' && str[r]=='p')
            l++, r--;
        else if(str[l]=='p' || str[r]=='q')
            flag = false, l++, r--;
        else if(str[l]==str[r])
            l++, r--;
        else
            flag = false, l++, r--;
    }
    
    cout << (flag ? "TAK" : "NIE") << endl;
    return 0;
}


int main(){
    fastio;

    ll t = 1;
    while(t--)
        solve();

    return 0;
}


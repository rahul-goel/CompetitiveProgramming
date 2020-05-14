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
    string s1 = "Danil", s2 = "Olya", s3 = "Slava", s4 = "Ann", s5 = "Nikita";
    ll pos = 0, c1=0, c2=0, c3=0, c4=0, c5=0;
    pos = 0;
    pos = 0;
    while ((pos = str.find(s1, pos )) != std::string::npos) {
          c1++;
          pos += s1.length();
    }
    pos = 0;
    while ((pos = str.find(s2, pos )) != std::string::npos) {
          c2++;
          pos += s2.length();
    }
    pos = 0;
    while ((pos = str.find(s3, pos )) != std::string::npos) {
          c3++;
          pos += s3.length();
    }
    pos = 0;
    while ((pos = str.find(s4, pos )) != std::string::npos) {
          c4++;
          pos += s4.length();
    }
    pos = 0;
    while ((pos = str.find(s5, pos )) != std::string::npos) {
          c5++;
          pos += s5.length();
    }
    if(c1+c2+c3+c4+c5 == 1)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}


int main(){
    fastio;

    ll t = 1;
    while(t--)
        solve();

    return 0;
}


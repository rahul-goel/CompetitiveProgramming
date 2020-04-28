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
    string str, ans = "";
    cin >> str;
    if(count(all(str), '0') == str.size()){
        cout << str << endl;
        return 0;
    }
    if(count(all(str), '1') == str.size()){
        cout << str << endl;
        return 0;
    }
    ans += str[0];
    for(int i=1; i<str.size(); ){
        if(ans[ans.size()-1] == '0' && str[i] == '0')
            ans += '1';
        else if(ans[ans.size()-1] == '0')
            ans += '1', i++;
        else if(ans[ans.size()-1] == '1' && str[i] == '1')
            ans += '0';
        else
            ans += '0', i++;
    }
    cout << ans << endl;
    return 0;
}

int main(){
    fastio;

    ll t = 1;
    cin >> t;
    while(t--)
        solve();

    return 0;
}

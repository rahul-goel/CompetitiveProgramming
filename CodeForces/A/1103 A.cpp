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
    string str;
    cin >> str;
    ll vcount = 0, hcount = 0;
    pii v1 = {1, 1}, v2 = {3, 1};
    pii h1 = {1, 3}, h2 = {2, 3}, h3 = {3, 3}, h4 = {4, 3};
    for(char x : str){
        if(x == '0'){
            if(vcount==0)
                cout << v1.f << " " << v1.s << endl, vcount++;
            else
                cout << v2.f << " " << v2.s << endl, vcount--;
        }
        else{
            if(hcount==0)
                cout << h1.f << " " << h1.s << endl, hcount++;
            else if(hcount == 1)
                cout << h2.f << " " << h2.s << endl, hcount++;
            else if(hcount == 2)
                cout << h3.f << " " << h3.s << endl, hcount++;
            else
                cout << h4.f << " " << h4.s << endl, hcount=0;
        }
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

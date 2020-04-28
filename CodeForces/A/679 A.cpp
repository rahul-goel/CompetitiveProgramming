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
    bool flag = false;
    string str;
    ll arr[] = {4, 9, 25, 49};
    for(ll i=0; i<4; i++){
        cout << arr[i] << endl;
        cin >> str;
        if(str == "yes")
            flag = true;
    }
    if(flag){
        cout << "composite" << endl;
        return 0;
    }

    ll arr2[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};

    ll count = 0;
    
    for(ll i=0; i<15; i++){
        cout << arr2[i] << endl;
        cin >> str;
        if(str == "yes")
            count++;
    }

    if(count > 1)
        cout << "composite" << endl;
    else
        cout << "prime" << endl;


    return 0;
}

int main(){
    fastio;

    ll t = 1;
    while(t--)
        solve();

    return 0;
}

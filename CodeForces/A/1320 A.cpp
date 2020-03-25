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

using namespace std;
typedef long long ll;
ll mod = 1000000007;
const int INF = 1000000000;

#define pii pair < int, int >
#define vi vector < int >
#define vvi vector < vector < int > >
#define vpii vector < pair < int, int > >
#define vvpii vector < vector < pair < int, int > > >
#define pb push_back
#define f first
#define s second
#define mp make_pair

int main(){
    ll n;
    cin >> n;
    vpii vec;
    for(ll i=0; i<n; i++){
        ll r;
        cin >> r;
        vec.pb({r-i-1, r});
    }
    // stable sort
    stable_sort(vec.begin(), vec.end());
    ll value = 0, i=0;
    while(i<n){
        ll temp = vec[i].s;
        while(i<n && vec[i].f == vec[i+1].f)
            temp += vec[i+1].s, i++;

        value = max(value, temp);
        i++;        
    }
    cout << value << endl;
    return 0;
}

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
#define pii pair < int, int >
#define vi vector < int >
#define vb vector < bool >
#define vvi vector < vector < int > >
#define vvb vector < vector < bool > >
#define vpii vector < pair < int, int > >
#define vvpii vector < vector < pair < int, int > > >
#define pb push_back
#define f first
#define s second
#define mp make_pair

int gcd(int a, int b){
    if(!b)
        return a;
    return gcd(b, a%b);
}

int main(){
    fastio;
    int x, t, a, b, da, db;
    cin >> x >> t >> a >> b >> da >> db;
    
    if(x == 0){
        cout << "YES" << endl;
        return 0;
    }

    for(int i=0; i<t; i++){
        for(int j=0; j<t; j++){
            if(i*da + j*db == a + b - x || a-x == i*da || b-x == j*db){
                cout << "YES" << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;

    return 0;
}

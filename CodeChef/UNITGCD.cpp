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

int main(){
    fastio;

    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        
        if(n == 1){
            cout << "1\n1 1\n";
        }
        else if(n == 2){
            cout << "1\n2 1 2\n";
        }
        else{
            cout << n/2 << '\n';
            cout << "3 1 2 3\n";
            for(int i=4; i<=n; i+=2){
                if(i+1 <=n)
                    cout << 2 << " " << i << " " <<  i+1 << '\n';
                else
                    cout << 1 << " " << i << '\n';
            }
            
        }
    }

    return 0;
}

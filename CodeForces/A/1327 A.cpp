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
    ll t;
    cin >> t;
    while(t--){
        ll n, k;
        cin >> n >> k;
        if((n+k)%2 == 1)
            cout << "NO" << endl;
        else if((n+k)%2 == 0 && (n+k)>=k*(k+1))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}

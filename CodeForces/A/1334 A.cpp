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
const int INF = 1000000000;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
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

int main(){
    fastio;
        
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int lvl = 0, clr = 0;
        bool flag = true;
        for(int i=0; i<n; i++){
            int l, c;
            cin >> l >> c;
            if(clr > c)
                flag = false;
            if(lvl > l)
                flag = false;
            if(l-lvl < c-clr)
                flag = false;
            lvl = max(lvl, l);
            clr = max(clr, c);
            if(clr > lvl)
                flag = false;
        }
        cout << (flag ? "YES" : "NO") << endl;
    }
    return 0;
}

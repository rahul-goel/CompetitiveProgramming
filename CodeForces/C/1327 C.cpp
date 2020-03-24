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
    int n, m, k;
    cin >> n >> m >> k;

    for(int i=0; i<k*2; i++){
        int x, y;
        cin >> x >> y;
    }

    string ans = "";
    for(int i=0; i<n-1; i++)
        ans += "D";
    for(int i=0; i<m-1; i++)
        ans += "R";
    bool x = true;
    for(int i=0; i<n; i++){

        if(x){
            for(int j=0; j<m-1; j++)
                ans += "L";   
            x = !x;
        }
        else{
            for(int j=0; j<m-1; j++)
                ans += "R";   
            x = !x;
        }

        ans += "U";
    }
    cout << ans.length() << endl;
    cout << ans << endl;
    return 0;
}

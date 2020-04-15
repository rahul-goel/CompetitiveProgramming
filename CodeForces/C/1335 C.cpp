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

int main(){
    fastio;
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vi vec(n), arr(n+5, 0);
        for(int i=0; i<n; i++)
            cin >> vec[i], arr[vec[i]]++;

        int ind = -1, mx = -1, count = 0;
        for(int i=0; i<n+5; i++){
            if(arr[i] > mx)
                ind = i, mx = arr[i];
            if(arr[i])
                count++;
        }
        count--;
        if(mx > count + 1)
            cout << count + 1 << endl;
        else if(mx == count + 1)
            cout << count << endl;
        else
            cout << mx << endl;
        
    }

    return 0;
}

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
#define vb vector < bool >
#define vvi vector < vector < int > >
#define vvb vector < vector < bool > >
#define vpii vector < pair < int, int > >
#define vvpii vector < vector < pair < int, int > > >
#define pb push_back
#define f first
#define s second
#define mp make_pair

void solve(){
    int n;
    cin >> n;
    vi vec(n);

    for(int i=0; i<n; i++)
        cin >> vec[i];

    if(count(vec.begin(), vec.end(), vec[0]) == n){
        cout << 1 << endl;
        for(int i=0; i<n; i++)
            cout << 1 << " ";
        cout << endl;
        return ;
    }

    if(n%2 == 0){
        cout << 2 << endl;
        for(int i=0; i<n; i++)
            cout << i%2 + 1 << " ";
        cout << endl;
        return;
    }

    for(int i=0; i<n; i++){
        if(vec[i] == vec[(i+1)%n]){
            vi ans(n);
            int j = 0;
            for(int pos = i+1; pos<n; pos++)
                ans[pos] = j+1, j^=1;
            j=0;
            for(int pos = i; pos>=0; pos--)
                ans[pos] = j+1, j^=1;

            cout << 2 << endl;
            for(int i=0; i<n; i++)
                cout << ans[i] << " ";
            cout << endl;
            return ;

        }
    }

    cout << 3 << endl;
    for(int i=0; i<n-1; i++)
        cout << i%2 + 1 << " ";
    cout << 3 << endl;
    return;
}

int main(){
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}

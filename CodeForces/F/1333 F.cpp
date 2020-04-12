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

vvi divisors;

bool cmp(int a, int b){
    return divisors[a][divisors[a].size()-2] < divisors[b][divisors[b].size()-2];
}

int main(){
    int n;
    cin >> n;
    divisors.resize(n+5);
    
    for(int i=1; i<=n; i++)
        for(int j=i; j<=n; j+=i)
            divisors[j].pb(i);
    vi vec;
    for(int i=2; i<=n; i++)
        vec.pb(i);
    sort(vec.begin(), vec.end(), cmp);
    vi count(n+5, 0);
    int ans = 1;
    for(int i=0; i<(int)vec.size(); i++){
        for(int u : divisors[vec[i]]){
            count[u]++;
            if(count[u] >= 2)
                ans = max(ans, u);
        }
        cout << ans << " ";
    }
    cout << endl;
    return 0;
}

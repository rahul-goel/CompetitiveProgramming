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
        int n, a, b;
        string str = "";
        cin >> n >> a >> b;
        char c = 'a';
        for(int i=0; i<b; i++)
            str += c++;
        c = str[b-1];
        for(int i=0; i<a-b; i++)
            str += c;
        int len = str.length();
        string sss = str;
        for(int i=0; i<n/len + 1; i++)
            str += sss;
        for(int i=0; i<n; i++)
            printf("%c", str[i]);
        printf("\n");
    }
    return 0;
}

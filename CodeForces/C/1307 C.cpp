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
 
#define pii pair < ll, ll >
#define vi vector < ll >
#define vvi vector < vector < ll > >
#define vpii vector < pair < ll, ll > >
#define vvpii vector < vector < pair < ll, ll > > >
#define pb push_back
#define f first
#define s second
#define mp make_pair

int main(){
    string str;
    cin >> str;
    ll len = str.size();

    vi vec1(26, 0);
    vvi vec2(26, vi(26, 0));

    for(ll i=0; i<len; i++)
        str[i]-='a';

    for(char c : str){
        for(ll i=0; i<26; i++)
            vec2[i][c] += vec1[i];
        vec1[c]++;
    }

    ll ans = 0;
    for(ll i=0; i<26; i++)
        ans = max(ans, vec1[i]);
    for(ll i=0; i<26; i++)
        for(ll j=0; j<26; j++)
            ans = max(ans, vec2[i][j]);

    cout << ans << endl;
    return 0;
}

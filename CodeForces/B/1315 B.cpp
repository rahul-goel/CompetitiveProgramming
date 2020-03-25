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
    int t;
    cin >> t;
    while(t--){
        string str;
        int a, b, p;
        cin >> a >> b >> p;
        cin >> str;
        int len = str.size(), ans = len, value=0, i=len-2;

        while(i>=0){
            while(i>=0 && str[i-1] == str[i])
                i--;
            if(str[i] == 'A')
                value += a;
            else
                value += b;

            if(value > p)
                break;
            ans = i+1, i--;
        }

        cout << ans << endl;

    }
    return 0;
}

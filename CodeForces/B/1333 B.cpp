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

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vi a(n), b(n);
        for(int i=0; i<n; i++)
            cin >> a[i];
        for(int i=0; i<n; i++)
            cin >> b[i];

        if(a[0] != b[0]){
            cout << "NO" << endl;
            continue;
        }
        
        bool one = false, neg = false, flag = true;
        if(a[0] == 1)
            one = true;
        else if(a[0] == -1)
            neg = true;
        for(int i=1; i<n; i++){
            if(b[i] > a[i]){
                if(one == false)
                    flag = false;
            }
            else if(b[i] < a[i]){
                if(neg == false)
                    flag = false;
            }
            if(a[i] == 1)
                one = true;
            else if(a[i] == -1)
                neg = true;
        }
        if(flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}

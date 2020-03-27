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
        int n, k, x;
        cin >> n >> k;
        for(int i=n-2; i>=0; i--){
            if(k>n-i-1){
                k-=n-i-1;
            }
            else{
                for(int j=0; j<i; j++)
                    cout << 'a';
                cout << 'b';
                for(int j=i+1; j<n-k; j++)
                    cout << 'a';
                cout << 'b';
                for(int j=n-k+1; j<n; j++)
                    cout << 'a';
                cout << endl;
                break;
            }
        }
    }
    return 0;
}

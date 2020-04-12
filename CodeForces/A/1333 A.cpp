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
        int n, m;
        cin >> n >> m;
        vector < vector < char > > mat(n, vector < char >(m));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if((i+j)%2==0)
                    mat[i][j] = 'B';
                else
                    mat[i][j] = 'W';
            }          
        }
        if((n*m)%2 == 0){
            if(n%2 == 0)
                mat[n-1][0] = 'B';
            else
                mat[n-1][m-1] = 'B';
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++)
                cout << mat[i][j];
            cout << endl;
        }
    }
    return 0;
}

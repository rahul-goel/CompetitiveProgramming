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
        char mat[9][9];
        for(int i=0; i<9; i++)
            for(int j=0; j<9; j++)
                cin >> mat[i][j];
        mat[0][2] = mat[1][2];
        mat[3][1] = mat[4][1];
        mat[6][0] = mat[7][0];

        mat[1][5] = mat[2][5];
        mat[4][4] = mat[5][4];
        mat[7][3] = mat[8][3];

        mat[2][8] = mat[0][8];
        mat[5][7] = mat[3][7];
        mat[8][6] = mat[6][6];

        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++)
                cout << mat[i][j];
            cout << endl;
        }
    }

    return 0;
}

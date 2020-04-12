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
    int n;
    cin >> n;
    int x = 1;

    if(n < 3){
        cout << -1 << endl;
        return 0;
    }

    int mat[505][505];
    bool visited[505][505];
    for(int i=0; i<505; i++)
        for(int j=0; j<505; j++)
            visited[i][j] = true;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            visited[i][j] = false;

    visited[1][1] = visited[1][2] = visited[1][3] = true;
    visited[2][1] = visited[2][2] = visited[2][3] = true;
    visited[3][1] = visited[3][2] = visited[3][3] = true;

    for(int i=n; i>3; i-=2){
        int j = 1;
        while(!visited[i][j]){
            mat[i][j] = x++;
            visited[i][j] = true;
            j++;
        }
        j--;
        int k = i-1;
        while(!visited[k][j]){
            mat[k][j] = x++;
            visited[k][j] = true;
            k--;
        }
        j--, k++;
        while(!visited[k][j]){
            mat[k][j] = x++;
            visited[k][j] = true;
            k++;
        }
        k--, j--;
        while(!visited[k][j]){
            mat[k][j] = x++;
            visited[k][j] = true;
            j--;
        }
    }
    
    x = n*n;
    if(n&1){
        mat[1][1] = x, mat[1][2] = x-4, mat[1][3] = x-3;
        mat[2][1] = x-2, mat[2][2] = x-7, mat[2][3] = x-1;
        mat[3][1] = x-8, mat[3][2] = x-6, mat[3][3] = x-5;
    }
    else{
        mat[1][1] = x, mat[1][2] = x-2, mat[1][3] = x-8;
        mat[2][1] = x-4, mat[2][2] = x-7, mat[2][3] = x-6;
        mat[3][1] = x-3, mat[3][2] = x-1, mat[3][3] = x-5;
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }

    return 0;
}

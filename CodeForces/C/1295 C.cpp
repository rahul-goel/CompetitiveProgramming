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
        string ss, tt;
        cin >> ss >> tt;
        int lenss=ss.size(), lentt = tt.size();

        vector < bool > ass(26, false), att(26, false);
        for(int i=0; i<lenss; i++)
            ass[ss[i]-'a'] = true;
        for(int i=0; i<lentt; i++)
            att[tt[i]-'a'] = true;
        bool flag = true;
        for(int i=0; i<26; i++){
            if(att[i] && !ass[i])
                flag = false;
        }
        if(flag == false){
            cout << -1 << endl;
            continue;
        }

        vector < vector < int > > nxt(lenss, vector < int > (26, INF));
        vector < int > vec(26, INF);

        for(int i=lenss-1; i>=0; i--){
            vec[ss[i]-'a'] = i; 
            nxt[i] = vec;
        }

        int count = 1;
        for(int i=0, j=0; i<lentt; ){
            if(j==lenss || nxt[j][tt[i]-'a'] == INF)
                count++, j=0;
            else if(nxt[j][tt[i]-'a'] != j)
                j = nxt[j][tt[i]-'a'];
            else
                i++, j++;
        }

        cout << count << endl;
    }
    return 0;
}

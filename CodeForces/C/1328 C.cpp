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
        int len, i=0;
        string str;
        cin >> len;
        cin >> str;
        string a="", b="";

        while(i<len && str[i]!='1'){
            if(str[i] == '2')
                a+='1', b+='1', i++;
            else
                a+='0', b+='0', i++;
        }

        if(i<len && str[i] == '1'){
            a+='1', b+='0', i++;
        }
        if(i==len){
            cout << a << endl;
            cout << b << endl;
            continue;
        }

        while(i<len)
            b+=str[i], a+='0', i++;
            cout << a << endl;
            cout << b << endl;
        
    }
    return 0;
}

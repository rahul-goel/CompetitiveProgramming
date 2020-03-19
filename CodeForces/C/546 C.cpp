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
#include <map>

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

int main()
{
	queue < int > st1, st2;
	map < queue < int >, int > mapping1, mapping2;	
	int n;
	cin >> n;
	int k1, k2;
	
	cin >> k1;
	while(k1--){
		int card;
		cin >> card;
		st1.push(card);
	}
	cin >> k2;
	while(k2--){
		int card;
		cin >> card;
		st2.push(card);
	}
	
	mapping2.insert({st1, 1}), mapping2.insert({st2, 1});
	bool flag = false;
	int count = 0;
	while(true){
		if(st1.empty() || st2.empty())
			break;
		
		count++;
		if(st1.front() > st2.front()){
			st1.push(st2.front()), st1.push(st1.front());
			st1.pop(), st2.pop();
		}
		else{
			st2.push(st1.front()), st2.push(st2.front());
			st1.pop(), st2.pop();
		}
		if(count > 0 && (mapping1.count(st1) && mapping2.count(st2))){
			flag = true;
			break;
		}
		mapping1.insert({st1, 1}), mapping2.insert({st2, 1});
	}

	if(flag)
		cout << -1 << endl;
	else if(st1.empty())
		cout << count << " " << 2 << endl;
	else
		cout << count << " " << 1 << endl;
	return 0;
}

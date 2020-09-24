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

// for only lowercase alphabet characters. MAX_N = max length of the string
// use ll everywhere
const ll p1 = 31, p2 = 39;
ll mod1 = 1000000007, mod2 = 1000000009;
vector < ll > p_pow1, p_pow2;

void store_powers(ll MAX_N){
	p_pow1.resize(MAX_N), p_pow2.resize(MAX_N);
	p_pow1[0] = 1, p_pow2[0] = 1;

	for(ll i=1; i<MAX_N; i++)
		p_pow1[i] = (p_pow1[i-1]*p1)%mod1, p_pow2[i] = (p_pow2[i-1]*p2)%mod2;
}

vector < ll > rabin_karp(string const& check, string const& str){
	ll check_len = check.size(), str_len = str.size();

	vector < ll > hash_str1(str_len+1, 0), hash_str2(str_len+1, 0);
	for(ll i=0; i<str_len; i++){
		hash_str1[i+1] = (hash_str1[i] + ((str[i]-'a'+1)*p_pow1[i])%mod1)%mod1;
		hash_str2[i+1] = (hash_str2[i] + ((str[i]-'a'+1)*p_pow2[i])%mod2)%mod2;
	}
	ll hash_check1 = 0, hash_check2 = 0;
	for(ll i=0; i<check_len; i++){
		hash_check1 = (hash_check1 + ((check[i]-'a'+1)*p_pow1[i])%mod1)%mod1;
		hash_check2 = (hash_check2 + ((check[i]-'a'+1)*p_pow2[i])%mod2)%mod2;
	}

	vector < ll > occurences;
	for(ll i=0; i+check_len-1<str_len; i++){
		ll cur_h1 = (hash_str1[i+check_len] + mod1 - hash_str1[i])%mod1;
		ll cur_h2 = (hash_str2[i+check_len] + mod2 - hash_str2[i])%mod2;
		if(cur_h1 == (hash_check1 * p_pow1[i])%mod1  &&  cur_h2 == (hash_check2 * p_pow2[i])%mod2)
			occurences.pb(i);
	}
	return occurences;
}

int main()
{
	string str, check;
	cin >> str >> check;
	ll MAX_N = str.size();
	store_powers(MAX_N);
	vector < ll > occ = rabin_karp(check, str);
	for(ll u : occ)
		cout << u << endl;
	return 0;
}

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

struct StringHash1 {
  const ll P1 = 31;
  const ll M = 1000000000 + 7;
  const char low = 'a';
  ll n;
  vector<ll> hash;
  vector<ll> PP1;
  vector<ll> IPP1;

  ll power(ll x, ll y) {
    ll ret = 1;
    while (y) {
      if (y & 1)
        ret = (ret * x) % M;
      x = (x * x) % M;
      y >>= 1;
    }
    return ret;
  }

  StringHash1(string &str) {
    n = str.size();
    PP1.resize(n);
    PP1[0] = 1;
    for (int i = 1; i < (int)n; i++)
      PP1[i] = (PP1[i - 1] * P1) % M;
    IPP1.resize(n);
    IPP1[n - 1] = power(PP1[n - 1], M - 2); // inverse
    for (int i = n - 2; i >= 0; --i)
      IPP1[i] = (IPP1[i + 1] * P1) % M;

    hash.resize(n + 1); // +1 for convenience
    hash[0] = 0;
    for (int i = 0; i < (int)n; ++i) {
      hash[i + 1] = (hash[i] + (str[i] - low + 1) * PP1[i]) % M;
    }
  }

  // both inclusive and 0-indexed
  ll gethash(ll left, ll right) {
    return (hash[right + 1] - hash[left] + M) % M * IPP1[left] % M;
  }
};

struct StringHash2 {
  const ll P1 = 31;
  const ll P2 = 37;
  const ll M = 1000000000 + 7;
  const char low = 'a';
  ll n;
  vector<pair<ll, ll>> hash;
  vector<ll> PP1;
  vector<ll> IPP1;
  vector<ll> PP2;
  vector<ll> IPP2;

  ll power(ll x, ll y) {
    ll ret = 1;
    while (y) {
      if (y & 1)
        ret = (ret * x) % M;
      x = (x * x) % M;
      y >>= 1;
    }
    return ret;
  }

  StringHash2(string &str) {
    n = str.size();
    PP1.resize(n);
    PP1[0] = 1;
    for (int i = 1; i < (int)n; i++)
      PP1[i] = (PP1[i - 1] * P1) % M;
    IPP1.resize(n);
    IPP1[n - 1] = power(PP1[n - 1], M - 2); // inverse
    for (int i = n - 2; i >= 0; --i)
      IPP1[i] = (IPP1[i + 1] * P1) % M;
    PP2.resize(n);
    PP2[0] = 1;
    for (int i = 1; i < (int)n; i++)
      PP2[i] = (PP2[i - 1] * P2) % M;
    IPP2.resize(n);
    IPP2[n - 1] = power(PP2[n - 1], M - 2); // inverse
    for (int i = n - 2; i >= 0; --i)
      IPP2[i] = (IPP2[i + 1] * P2) % M;

    hash.resize(n + 1); // +1 for convenience
    hash[0] = pair<ll, ll>(0, 0);
    for (int i = 0; i < (int)n; ++i) {
      hash[i + 1].first = (hash[i].first + (str[i] - low + 1) * PP1[i]) % M;
      hash[i + 1].second = (hash[i].second + (str[i] - low + 1) * PP2[i]) % M;
    }
  }

  // both inclusive and 0-indexed
  pair<ll, ll> gethash(ll left, ll right) {
    return pair<ll, ll>(
        (hash[right + 1].first - hash[left].first + M) % M * IPP1[left] % M,
        (hash[right + 1].second - hash[left].second + M) % M * IPP2[left] % M);
  }
};

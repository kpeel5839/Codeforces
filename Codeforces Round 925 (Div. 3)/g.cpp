#include <algorithm>
#include <cmath>
#include <cstdio>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string.h>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;
#define y first
#define x second

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<vii> viii;
typedef vector<viii> viiii;
typedef vector<ll> vl;
typedef vector<vl> vll;
typedef vector<vll> vlll;
typedef vector<vlll> vllll;
typedef vector<char> vc;
typedef vector<vc> vcc;
typedef vector<vcc> vccc;
typedef vector<vccc> vcccc;
typedef vector<bool> vb;
typedef vector<vb> vbb;
typedef vector<vbb> vbbb;
typedef vector<vbbb> vbbbb;
const ll INF = 1e18;
const int inf = 2e9;
const int size = 1 << 18;
const int mod = 1e9 + 7;

namespace std {
template <> struct hash<std::vector<int>> {
  size_t operator()(const std::vector<int> &v) const {
    size_t hash_value = 0;
    for (int i : v) {
      hash_value ^= std::hash<int>()(i);
    }
    return hash_value;
  }
};
}
const ll MOD=998244353;
vector<ll> fact = {1};
ll pow_mod(ll x, ll p) {
  if (p == 0) {
    return 1;
  }
  if (p % 2 == 0) {
    ll y = pow_mod(x, p / 2);
    return (y * y) % MOD;
  }
  return (x * pow_mod(x, p - 1)) % MOD;
}
ll inv(ll x) {
  return pow_mod(x, MOD - 2);
}
ll cnk(ll n, ll k) {
  ll res = fact[n];
  res = (res * inv(fact[k])) % MOD;
  res = (res * inv(fact[n - k])) % MOD;
  return res;
}
ll calc(ll n1,ll n2,ll n3,int n4){
  return (cnk(n1+n3-1,n3)*cnk(n2+n4-1,n4))%MOD;
}
void solve() {
  int n1,n2,n3,n4;cin>>n1>>n2>>n3>>n4;
  if(1<abs(n1-n2)){
    cout<<"0"<<"\n";
    return;
  }
  if(n1==0&&n2==0){
    cout<<(n3==0||n4==0?1:0)<<"\n";
    return;
  }
  ll res=0;
  if(n1<=n2){
    res+=calc(n1+1,n2,n3,n4);
  }
  if(n2<=n1){
    res+=calc(n1,n2+1,n3,n4);
  }
  cout<<(res%MOD)<<"\n";
}

int main(void) {
  for (ll i = 1; i <= 4e6; ++i) {
    fact.push_back((fact.back() * i) % MOD);
  }
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  // freopen("g.input.txt", "r", stdin);
  int T;
  cin >> T;
  while (T-- > 0) {
    solve();
  }
  return 0;
}

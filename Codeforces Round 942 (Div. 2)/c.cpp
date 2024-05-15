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
// const int inf = 2e9;
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

const ll MOD=1e7;
vl fact = {1};
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

ll n,k;
vl arr;
bool isPossible(ll m){
  ll sum=0;
  for(int i=0;i<arr.size();i++){
    if(m<=arr[i]){
      continue;
    }
    sum+=m-arr[i];
    if(k<sum){
      return false;
    }
  }
  return true;
}
void solve() {
  cin>>n>>k;
  arr=vl(n,0);
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  ll l=1;
  ll r=1e13;
  ll answer=0;
  while(l<=r){
    ll m=(l+r)/2;
    if(isPossible(m)){
      answer=m;
      l=m+1;
    }else{
      r=m-1;
    }
  }
  for(int i=0;i<n;i++){
    if(answer<=arr[i]){
      continue;
    }
    k-=answer-arr[i];
    arr[i]=answer;
  }
  for(int i=0;i<n;i++){
    if(answer<arr[i]){
      continue;
    }
    if(k<=0){
      break;
    }
    arr[i]++;
    k--;
  }
  sort(arr.begin(),arr.end(),[](ll o1,ll o2){
    return o1>o2;
  });
  ll cnt=0;
  for(int i=0;i<n;i++){
    if(answer<arr[i]){
      cnt++;
      continue;
    }
    break;
  }
  cout<<((answer-1ll)*n+1ll+cnt)<<"\n";
}

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("c.input.txt", "r", stdin);
  int T;
  cin >> T;
  while (T-- > 0) {
    solve();
  }
  return 0;
}

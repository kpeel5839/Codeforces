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

int N;
void solve() {
  cin>>N;
  for(int i=0;i<2*N;i++){//i/2==1일때에는오히려출력x
    for(int j=0;j<2*N;j++){
      if((i/2)%2==1){//이때에는,출력을 처음을 .을하면됨
        if((j/2)%2==1){
          cout<<"#";
        }else{
          cout<<".";
        }
      }else{
        if((j/2)%2==1){
          cout<<".";
        }else{
          cout<<"#";
        }
      }
    }
    cout<<"\n";
  }
}

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("b.input.txt", "r", stdin);
  int T;
  cin >> T;
  while (T-- > 0) {
    solve();
  }
  return 0;
}

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

vbb isPossible;
vii dp;
int n;
vector<string> w;
vector<string> g;
int dfs(int bit,int now){
  if(dp[bit][now]!=-1){
    return dp[bit][now];
  }
  dp[bit][now]=0;
  for(int i=0;i<n;i++){
    if(now==i){
      continue;
    }
    if((bit&(1<<i))==0&&isPossible[now][i]){
      dp[bit][now]=max(dp[bit][now],dfs(bit|(1<<i),i)+1);
    }
  }
  return dp[bit][now];
}
void getIsPossible(){
  for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
      if(w[i]==w[j]||g[i]==g[j]){
        isPossible[i][j]=true;
        isPossible[j][i]=true;
      }
    }
  }
}
void solve() {
  cin>>n;
  int answer=0;
  isPossible=vbb(n,vb(n,false));
  dp=vii(1<<n,vi(n,-1));
  w=vector<string>(n);
  g=vector<string>(n);
  for(int i=0;i<n;i++){
    cin>>w[i]>>g[i];
  }
  getIsPossible();
  for(int i=0;i<n;i++){
    answer=max(answer,dfs(1<<i,i)+1);
  }
  cout<<(n-answer)<<"\n";
}

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("g.input.txt", "r", stdin);
  int T;
  cin >> T;
  while (T-- > 0) {
    solve();
  }
  return 0;
}

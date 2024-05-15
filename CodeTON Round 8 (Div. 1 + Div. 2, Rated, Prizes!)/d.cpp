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
struct comp{
  bool operator()(vi& o1,vi& o2){
    return o1[0]<o2[0];
  }
};

int n,k;
void solve() {
  cin>>n>>k;
  vii arr(n+1,vi(n+1,0));
  for(int i=1;i<=n;i++){
    for(int j=i;j<=n;j++){
      cin>>arr[i][j];
    }
  }
  vii dp(n+1);
  dp[0].push_back(0);
  for(int i=1;i<=n;i++){
    priority_queue<vi,vii,comp>q;//{value,idx,dp idx}
    q.push({dp[i-1][0],i-1,0});
    q.push({arr[1][i],-1,0});
    for(int j=i-2;0<=j;j--){
      q.push({dp[j][0]+arr[j+2][i],j,0});
    }
    while(q.size()!=0&&dp[i].size()<k){
      vi vv=q.top();q.pop();
      int v=vv[0],iIdx=vv[1],jIdx=vv[2];
      dp[i].push_back(v);
      if(iIdx<0||jIdx+1==dp[iIdx].size()){
        continue;
      }
      if(iIdx==i-1){
        q.push({dp[i-1][jIdx+1],iIdx,jIdx+1});
      }else{
        q.push({dp[iIdx][jIdx+1]+arr[iIdx+2][i],iIdx,jIdx+1});
      }
    }
  }
  for(auto v:dp[n]){
    cout<<v<<" ";
  }
  cout<<"\n";
}

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("d.input.txt", "r", stdin);
  int T;
  cin >> T;
  while (T-- > 0) {
    solve();
  }
  return 0;
}

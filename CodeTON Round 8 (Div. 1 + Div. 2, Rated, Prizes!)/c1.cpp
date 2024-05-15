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

int n,m,k;
vl arr;
void solve() {
  cin>>n>>m>>k;
  arr=vl(m);
  for(auto&v:arr){
    cin>>v;
  }
  sort(arr.begin(),arr.end());
  int selectCnt=1;
  int additional=0;
  vi even;
  vi odd;
  for(int i=0;i<arr.size();i+=0){
    if(arr.size()-1==i){
      int distance=arr[0]-(arr[i]-n);
      if(distance==2){
        additional++;
      }else if(2<distance){
        int cnt=distance-1;
        if(cnt%2==0){
          even.push_back(cnt);
        }else{
          odd.push_back(cnt);
        }
      }
      i++;
      continue;
    }
    if(arr[i+1]-arr[i]==1){
      if(arr.size()<=i+2){
        if(arr[0]-(arr[i]-n)==2){
          additional++;
          i+=2;
          continue;
        }
        selectCnt++;
        i++;
        continue;
      }
      if(arr[i+2]-arr[i]==2){
        additional++;
        selectCnt++;
        i+=2;
        continue;
      }
      selectCnt++;
      i++;
      continue;
    }
    selectCnt++;
    if(arr[i+1]-arr[i]==2){
      additional++;
    }else if(2<arr[i+1]-arr[i]){
      int cnt=arr[i+1]-arr[i]-1;
      if(cnt%2==0){
        even.push_back(cnt);
      }else{
        odd.push_back(cnt);
      }
    }
    i++;
  }
  sort(odd.begin(),odd.end());
  sort(even.begin(),even.end());
  for(int i=0;i<odd.size();i++){
    if(k==0){
      break;
    }
    int cnt=odd[i];
    selectCnt+=min(k,(int)cnt/2);
    additional+=min(k,(int)cnt/2);
    if((int)cnt/2<=k){
      additional++;
    }
    k-=min(k,(int)cnt/2);
  }
  for(int i=0;i<even.size();i++){
    if(k==0){
      break;
    }
    int cnt=even[i];
    selectCnt+=min(k,(int)cnt/2);
    additional+=min(k,(int)cnt/2);
    k-=min(k,(int)cnt/2);
  }
  if(selectCnt==3){
    selectCnt=1;
  }else if(selectCnt<3){
    selectCnt=0;
  }else{
    selectCnt=2+(selectCnt-4);
  }
  cout<<selectCnt+additional<<"\n";
}

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("c1.input.txt", "r", stdin);
  int T;
  cin >> T;
  while (T-- > 0) {
    solve();
  }
  return 0;
}

#include <algorithm>
#include <sstream>
#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
#include <deque>
#include <string.h>
#include <cstdio>
#include <cmath> 
#include <set>
#include <map>

using namespace std;

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

int N;
vl arr;
vl prefixSum;

struct comp{
  bool operator()(vl&o1,vl&o2){
    if(o1[1]==o2[1]){
      return o1[0]>o2[0];
    }
    return o1[1]>o2[1];
  }
};

ll rangeSum(ll l,ll r){
  if(r<0||arr.size()<=l||r<l){
    return 0;
  }
  if(l<=0){
    return prefixSum[r];
  }
  return prefixSum[r]-prefixSum[l-1];
}

bool isPossible(ll m){
  priority_queue<vl,vll,comp>q; //{index,value}
  q.push({-1,0});
  ll sumMin=INF;
  vl dp(arr.size(),0);
  for(int i=0;i<arr.size();i++){
    while(q.size()!=0&&m<rangeSum(q.top()[0]+1,i-1)){
      q.pop();
    }
    if(q.size()==0){
      return false;
    }
    vl v=q.top();
    q.push({i,v[1]+arr[i]});
    dp[i]=v[1]+arr[i];
  }
  for(int i=arr.size()-1;0<=i;i--){
    if(rangeSum(i+1,arr.size()-1)<=m){
      sumMin=min(sumMin,dp[i]);
    }
  }

  return sumMin<=m;
}

void solve() {
  cin>>N;
  arr=vl(N+1,0);
  prefixSum=vl(N+1,0);
  for(int i=0;i<N;i++){
    cin>>arr[i];
  }
  prefixSum[0]=arr[0];
  for(int i=1;i<=N;i++){
    prefixSum[i]=arr[i]+prefixSum[i-1];
  }
  ll l=1;
  ll r=1e17;
  ll answer=1;
  while(l<=r){
    ll m=(l+r)/2;
    if(isPossible(m)){
      r=m-1;
      answer=m;
    }else{
      l=m+1;
    }
  }
  cout<<answer<<"\n";
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	// freopen("d.input.txt", "r", stdin);
  int T;cin>>T;
  while (T-- > 0) {
    solve();
  }
	return 0;
}
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
  template<>
  struct hash<std::vector<int>> {
    size_t operator()(const std::vector<int>& v) const {
      size_t hash_value = 0;
      for (int i : v) {
        hash_value ^= std::hash<int>()(i);
      }
      return hash_value;
    }
  };
}
struct comp{
  bool operator()(ll o1,ll o2){
    return o1<o2;
  }
};
int a,b,c;
void solve() {
  cin>>a>>b>>c;
  vi A(a);
  vi B(b);
  vi C(c);
  for(auto&v:A){
    cin>>v;
  }
  for(auto&v:B){
    cin>>v;
  }
  for(auto&v:C){
    cin>>v;
  }
  sort(A.begin(),A.end());
  sort(B.begin(),B.end());
  sort(C.begin(),C.end());
  int l=0;
  int r=C.size()-1;
  priority_queue<ll,vl,comp>q;
  ll maxE=0;
  vl range;
  for(int i=1;i<A.size();i++){
    ll diff=A[i]-A[i-1];
    q.push(diff);
    if(maxE<diff){
      maxE=diff;
      range={A[i-1],A[i]};
    }
  }
  maxE=q.top();q.pop();
  ll answer=maxE;
  while(l!=B.size()&&r!=-1){
    ll sum=B[l]+C[r];
    if(sum<(range[1]+range[0])/2.0){
      l++;
    }else{
      r--;
    }
    answer=min(answer,max(range[1]-sum,sum-range[0]));
  }
  cout<<max((q.size()==0?0:q.top()),answer)<<"\n";
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	// freopen("f.input.txt", "r", stdin);
  int T; cin >> T;
  while (T-- > 0) {
    solve();
  }
	return 0;
}
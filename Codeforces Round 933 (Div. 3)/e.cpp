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
  bool operator()(vl&o1,vl&o2){
    return o1[1]>o2[1];
  }
};
int H,W,M,D;
void solve() {
  cin>>H>>W>>M>>D;
  vll arr(H,vl(W,0));
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      cin>>arr[i][j];
    }
  }
  vl cost(H,INF);
  for(int i=0;i<H;i++){
    priority_queue<vl,vll,comp>q;
    q.push({0,1});
    for(int j=1;j<W;j++){
      while(q.size()!=0&&D<j-q.top()[0]-1){
        q.pop();
      }
      ll now=q.top()[1]+(arr[i][j]+1);
      q.push({j,now});
      if(j==W-1){
        cost[i]=now;
      }
    }
  }
  ll answer=INF;
  for(int i=0;i<H-M+1;i++){
    ll sum=0;
    for(int j=i;j<i+M;j++){
      sum+=cost[j];
    }
    answer=min(answer,sum);
  }
  cout<<answer<<"\n";
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	// freopen("e.input.txt", "r", stdin);
  int T; cin >> T;
  while (T-- > 0) {
    solve();
  }
	return 0;
}
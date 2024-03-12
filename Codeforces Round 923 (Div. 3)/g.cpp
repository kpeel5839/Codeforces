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
int N;
void solve() {
  cin>>N;
  vi arr(N);
  viii dp(N+1,vii(N+1,vi(N+1,inf)));
  arr=vi(N);
  for(int i=0;i<N;i++){
    cin>>arr[i];
  }
  dp[0][0][0]=0;
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      for(int k=0;k<=N;k++){
        if(dp[i][j][k]<inf){
          int ai=arr[i];
          //그냥 앞으로
          {
            int ni=i+1;
            int nj=j>0?j+1:(k==0?1:0);
            int nk=max(0,k-1);
            dp[ni][nj][nk]=min(dp[ni][nj][nk],dp[i][j][k]);
          }
          //왼쪽으로분사
          {
            int ni=i+1;
            int nj=j>0?j+1:0;
            if(nj<=ai){
              nj=0;
            }
            int nk=max(0,k-1);
            dp[ni][nj][nk]=min(dp[ni][nj][nk],dp[i][j][k]+1);
          }
          //오른쪽으로분사
          {
            int ni=i+1;
            int nj=j>0?j+1:0;
            int nk=max(ai-1,k-1);
            dp[ni][nj][nk]=min(dp[ni][nj][nk],dp[i][j][k]+1);
          }
        }
      }
    }
  }
  cout<<*min_element(dp[N][0].begin(),dp[N][0].end())<<"\n";
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	// freopen("g.input.txt", "r", stdin);
  int T; cin >> T;
  while (T-- > 0) {
    solve();
  }
	return 0;
}
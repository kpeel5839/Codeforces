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

int N,M,start;
void solve() {
  cin>>N>>M>>start;
  start--;
  vbb visited(M+1,vb(N,false));
  vii thrown(M);
  for(int i=0;i<M;i++){
    int r;string s;cin>>r>>s;
    thrown[i]={r,s=="?"?2:s.at(0)-'0'};
  }
  queue<vi>q;//{idx,m}
  q.push({start,0});
  visited[0][start]=true;
  while(q.size()!=0){
    vi p=q.front();q.pop();
    if(p[1]==M){
      continue;
    }
    vi now=thrown[p[1]];
    if(now[1]==2){
      int clockWise=(p[0]+now[0])%N;
      int countClockWise=(p[0]+N-now[0])%N;
      if(!visited[p[1]+1][countClockWise]){
        visited[p[1]+1][countClockWise]=true;
        q.push({countClockWise,p[1]+1});
      }
      if(!visited[p[1]+1][clockWise]){
        visited[p[1]+1][clockWise]=true;
        q.push({clockWise,p[1]+1});
      }
    }else if(now[1]==1){
      int countClockWise=(p[0]+N-now[0])%N;
      if(!visited[p[1]+1][countClockWise]){
        visited[p[1]+1][countClockWise]=true;
        q.push({countClockWise,p[1]+1});
      }
    }else{
      int clockWise=(p[0]+now[0])%N;
      if(!visited[p[1]+1][clockWise]){
        visited[p[1]+1][clockWise]=true;
        q.push({clockWise,p[1]+1});
      }
    }
  }
  vi answer;
  for(int i=0;i<N;i++){
    if(visited[M][i]){
      answer.push_back(i+1);
    }
  }
  cout<<answer.size()<<"\n";
  for(auto v:answer){
    cout<<v<<" ";
  }
  cout<<"\n";
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	// freopen("d.input.txt", "r", stdin);
  int T; cin >> T;
  while (T-- > 0) {
    solve();
  }
	return 0;
}
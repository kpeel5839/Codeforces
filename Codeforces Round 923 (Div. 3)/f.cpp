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
vi parent;
int N,M;
int find(int x){
  if(parent[x]==x){
    return x;
  }
  return parent[x]=find(parent[x]);
}
void uni(int a,int b){
  parent[b]=a;
}
vii graph;
vi tracking;
int src,des;
bool dfs(int cur){
  if(cur==des){
    return true;
  }
  for(auto next:graph[cur]){
    if(tracking[next]) {
      continue;
    }
    tracking[next]=cur;
    if(dfs(next)){
      return true;
    }
  }
  return false;
}
void solve() {
  cin>>N>>M;
  vii edges;
  vi minimumEdge;
  parent=vi(N+1);
  for(int i=1;i<=N;i++){
    parent[i]=i;
  }
  for(int i=0;i<M;i++){
    int a,b,c;cin>>a>>b>>c;
    edges.push_back({a,b,c});
  }
  sort(edges.begin(),edges.end(),[](vi &a,vi &b){
    return a[2]>b[2];
  });
  for(int i=0;i<edges.size();i++){
    int a=find(edges[i][0]);
    int b=find(edges[i][1]);
    if(a==b){
      minimumEdge=edges[i];
    }else{
      uni(a,b);
    }
  }
  src=minimumEdge[0];
  des=minimumEdge[1];
  tracking=vi(N+1);
  graph=vii(N+1);
  for(auto v:edges){
    if(v[0]==minimumEdge[0]&&v[1]==minimumEdge[1]){
      continue;
    }
    graph[v[0]].push_back(v[1]);
    graph[v[1]].push_back(v[0]);
  }
  dfs(src);
  vi answer;
  int cur=des;
  while(true){
    answer.push_back(cur);
    if(cur==src){
      break;
    }
    cur=tracking[cur];
  }
  cout<<minimumEdge[2]<<" "<<answer.size()<<"\n";
  for(auto v:answer){
    cout<<v<<" ";
  }
  cout<<"\n";
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
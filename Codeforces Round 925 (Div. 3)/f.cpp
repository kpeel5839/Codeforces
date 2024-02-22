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

int N,S;
vii graph;

void solve() {
  cin>>N>>S;
  graph=vii(N+1);
  vi entry(N+1);
  for(int i=0;i<S;i++){
    vi arr(N+1,0);
    for(int j=0;j<N;j++){
      cin>>arr[j+1];
    }
    for(int j=2;j<=N-1;j++){
      graph[arr[j+1]].push_back(arr[j]);
      entry[arr[j]]++;
    }
  }
  queue<int>q;
  for(int i=1;i<=N;i++){
    if(entry[i]==0){
      q.push(i);
    }
  }
  while(q.size()!=0){
    int p=q.front();q.pop();
    for(auto v:graph[p]){
      if(--entry[v]==0){
        q.push(v);
      }
    }
  }
  for(int i=1;i<=N;i++){
    if(entry[i]!=0){
      cout<<"NO"<<"\n";
      return;
    }
  }
  cout<<"YES"<<"\n";
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
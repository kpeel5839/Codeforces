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
#include <chrono>

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
int N,M,src,des;
void solve() {
  cin>>N>>M;
  vector<unordered_set<int>>graph(N+1);
  unordered_map<int,unordered_set<int>>m;//이색깔이방문할수있는정점
  unordered_set<int>possible;
  unordered_set<int>visited;
  queue<vi>q;//{color,distance}
  for(int i=0;i<M;i++){
    int a,b,c;cin>>a>>b>>c;
    graph[a].insert(c);
    graph[b].insert(c);
    m[c].insert(a);
    m[c].insert(b);
  }
  cin>>src>>des;
  if(src==des){
    cout<<0<<"\n";
    return;
  }
  for(auto color:graph[src]){
    q.push({color,1});
    visited.insert(color);
  }
  for(auto color:graph[des]){
    possible.insert(color);
  }
  graph[src].clear();
  graph[des].clear();
  while(q.size()!=0){
    //색깔을빼고
    vi p=q.front();q.pop();
    if(possible.find(p[0])!=possible.end()){
      cout<<p[1]<<"\n";
      return;
    }
    //색깔이방문할수있는정점을전부돌아
    for(auto vertex:m[p[0]]){
      //vertex를 탐험하고 있으니,이 때,방문 가능한 정점에는 본인의 색깔도 빼고,방문하는색깔도뺴줌
      for(auto color:graph[vertex]){
        if(visited.find(color)!=visited.end()){
          continue;
        }
        q.push({color,p[1]+1});
        visited.insert(color);
      }
      graph[vertex]=unordered_set<int>();
    }
  }
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("g.input.txt", "r", stdin);
  // // 시작 시간 기록
  // auto start = std::chrono::high_resolution_clock::now();

  int T; cin >> T;
  while (T-- > 0) {
    solve();
  }
  // // 종료 시간 기록
  // auto end = std::chrono::high_resolution_clock::now();

  // // 소요된 시간 계산
  // std::chrono::duration<double> elapsed = end - start;

  // // 시간 출력
  // std::cout << "실행 시간: " << elapsed.count() << " 초" << std::endl;
	return 0;
}
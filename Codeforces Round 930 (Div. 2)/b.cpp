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
int N;
vii m;
vi dx={0,1};
vi dy={1,0};
vll dp;
vi minNumber;
bool isOutOfRange(int y,int x){
  return y<0||y>=2||x<0||x>=N;
}
int dfs(int y,int x,int sequence){
  if(y==1&&x==N-1){
    return 1;
  }
  if(dp[y][x]!=-1){
    return dp[y][x];
  }
  dp[y][x]=0;
  for(int i=0;i<2;i++){
    int ny=y+dy[i];
    int nx=x+dx[i];
    if(isOutOfRange(ny,nx)||minNumber[sequence+1]<m[ny][nx]){
      continue;
    }
    dp[y][x]+=dfs(ny,nx,sequence+1);
  }
  return dp[y][x];
}

void solve() {
  cin>>N;
  m=vii(2,vi(N,0));
  for(int i=0;i<2;i++){
    string s;cin>>s;
    for(int j=0;j<N;j++){
      m[i][j]=(s.at(j)-'0');
    }
  }
  int answer=0;
  string ans;
  queue<vi>q;
  vbb visited(2,vb(N,false));
  q.push({0,0,0});
  minNumber=vi(N+1,inf);
  minNumber[0]=m[0][0];
  dp=vll(2,vl(N,-1));
  while(q.size()!=0){
    vi p=q.front();q.pop();
    if(minNumber[p[2]]<m[p[0]][p[1]]){
      continue;
    }
    if(p[0]==1&&p[1]==N-1){
      answer++;
      continue;
    }
    for(int i=0;i<2;i++){
      int ny=p[0]+dy[i];
      int nx=p[1]+dx[i];
      if(isOutOfRange(ny,nx)||visited[ny][nx]||minNumber[p[2]+1]<m[ny][nx]){
        continue;
      }
      visited[ny][nx]=true;
      q.push({ny,nx,p[2]+1});
      minNumber[p[2]+1]=min(minNumber[p[2]+1],m[ny][nx]);
    }
  }
  for(auto v:minNumber){
    ans.push_back(v+'0');
  }
  cout<<ans<<"\n"<<dfs(0,0,0)<<"\n";
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	// freopen("b.input.txt", "r", stdin);
  int T; cin >> T;
  while (T-- > 0) {
    solve();
  }
	return 0;
}
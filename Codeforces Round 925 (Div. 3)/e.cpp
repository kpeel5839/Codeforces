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

int N,M;
vpii arr;
void solve() {
  cin>>N>>M;
  arr=vpii();
  for(int i=0;i<N;i++){
    string s;cin>>s;
    int zeroCount=0;
    for(int j=s.length()-1;0<=j;j--){
      if(s.at(j)!='0'){
        break;
      }
      zeroCount++;
    }
    arr.push_back({s.length(),zeroCount});
  }
  sort(arr.begin(),arr.end(),[](pii& o1, pii& o2){
    if(o1.second==o2.second){
      return o1.first>o2.first;
    }
    return o1.second>o2.second;
  });
  deque<pii> q;
  for(int i=0;i<N;i++){
    q.push_back(arr[i]);
  }
  for(int i=0;i<N-1;i++){
    pii v=q.front();q.pop_front();
    v.first=v.first-v.second;
    v.second=0;
    q.push_back(v);

    pii vv=q.front();q.pop_front();
    pii vvv=q.front();q.pop_front();
    vvv.first=vvv.first+vv.first;
    q.push_front(vvv);
  }
  pii v=q.front();
  cout<<((v.first-v.second)>=M+1?"Sasha":"Anna")<<"\n";
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
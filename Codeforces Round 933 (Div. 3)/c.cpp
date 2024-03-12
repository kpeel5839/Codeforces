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
  string s;
  cin>>N>>s;
  int cnt=0;
  if(s.length()<=2){
    cout<<0<<"\n";
    return;
  }
  for(int i=0;i<s.length()-2;i++){
    string substring;
    for(int j=0;j<3;j++){
      substring.push_back(s.at(i+j));
    }
    bool mapOk=substring=="map";
    bool pieOk=substring=="pie";
    string subsubstring;
    if(i+5-1<=s.length()-1){
      for(int j=0;j<5;j++){
        subsubstring.push_back(s.at(i+j));
      }
      if(subsubstring=="mapie"){
        i+=4;
        cnt++;
        continue;
      }
    }
    if(mapOk){
      i+=2;
      cnt++;
    }else if(pieOk){
      i+=2;
      cnt++;
    }
  }
  cout<<cnt<<"\n";
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	// freopen("c.input.txt", "r", stdin);
  int T; cin >> T;
  while (T-- > 0) {
    solve();
  }
	return 0;
}
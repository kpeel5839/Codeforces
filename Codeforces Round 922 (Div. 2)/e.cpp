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

char query(int idx){
  cout<<"? "<<idx<<endl;
  char result;cin>>result;
  return result;
}
void dnq(int l,int r,vi&pos,vi&res,int pos1,int posn){
  int m=(l+r)/2;
  vi lm;
  vi rm;
  for(int i=0;i<pos.size();i++){
    char result=query(pos[i]);
    if(result=='>'){
      rm.push_back(pos[i]);
      query(pos1);
    }else if(result=='<'){
      lm.push_back(pos[i]);
      query(posn);
    }else{
      res[pos[i]]=m;
    }
  }
  if(lm.size()!=0){//down
    int m2=(l+m-1)/2;
    for(int i=0;i<m-m2;i++){
      query(pos1);
    }
    dnq(l,m-1,lm,res,pos1,posn);
    for(int i=0;i<m-m2;i++){
      query(posn);
    }
  }
  if(rm.size()!=0){//up
    int m2=(r+m+1)/2;
    for(int i=0;i<m2-m;i++){
      query(posn);
    }
    dnq(m+1,r,rm,res,pos1,posn);
    for(int i=0;i<m2-m;i++){
      query(pos1);
    }
  }
}
void solve() {
  int n; cin >> n;
  int pos1=-1;
  for(int i=1;i<=n;i++){
    char result=query(i);
    if(result=='>'){
      if(pos1!=-1){
        query(pos1);
      }
    }else if(result=='<'){
      i--;
    }else{
      pos1=i;
    }
  }
  int posn=-1;
  for(int i=1;i<=n;i++){
    char result=query(i);
    if(result=='>'){
      i--;
    }else if(result=='<'){
      if(posn!=-1){
        query(posn);
      }
    }else{
      posn=i;
    }
  }
  vi res(n+1);
  vi pos(n);
  for(int i=1;i<=n;i++){
    pos[i-1]=i;
  }
  int m=(1+n)/2;
  for(int i=0;i<n-m;i++){
    query(pos1);
  }
  dnq(1,n,pos,res,pos1,posn);
  cout<<"! ";
  for(int i=1;i<=n;i++){
    cout<<res[i]<<" ";
  }
  cout<<endl;
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("e.input.txt", "r", stdin);
  int T;cin>>T;
  while (T-- > 0) {
    solve();
  }
	return 0;
}
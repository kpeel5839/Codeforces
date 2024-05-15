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

char query(int a,int b,int c,int d){
    cout<<"? "<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
    char cc;cin>>cc;
    return cc;
}
void solve() {
    int n;cin>>n;
    int result1=0;
    for(int i=1;i<n;i++){
        char c=query(result1,result1,i,i);
        if(c=='<'){
            result1=i;
        }
    }
    vi v;
    int result2=result1;
    for(int i=0;i<n;i++){
        if(i==result1){
            continue;
        }
        char c=query(result1,result2,result1,i);
        if(c=='<'){
            result2=i;
            v=vi();
            v.push_back(i);
        }
        if(c=='='){
            v.push_back(i);
        }
    }
    vi nra;
    for(int i=0;i<v.size();i++){
        if(v[i]==result1){
            continue;
        }
        nra.push_back(v[i]);
    }
    result2=nra[0];
    for(int i=1;i<nra.size();i++){
        char c=query(result2,result2,nra[i],nra[i]);
        if(c=='>'){
            result2=nra[i];
        }
    }
    cout<<"! "<<result1<<" "<<result2<<endl;
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("c.input.txt", "r", stdin);
    int T; cin >> T;
    while (T-- > 0) {
        solve();
    }
	return 0;
}
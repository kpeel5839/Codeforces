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

void solve() {
    int n,q;cin>>n>>q;
    map<int,vector<int>>id;
    vl a(n+1,0);
    id[0].push_back(0);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        a[i]^=a[i-1];
        id[a[i]].push_back(i);
    }
    while(q-->0){
        int l,r;cin>>l>>r;
        if(a[l-1]==a[r]){
            cout<<"YES"<<"\n";
            continue;
        }
        int t=*--lower_bound(id[a[l-1]].begin(),id[a[l-1]].end(),r);
        int s=*lower_bound(id[a[r]].begin(),id[a[r]].end(),l);
        cout<<(s<t?"YES":"NO")<<"\n";
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("f.input.txt", "r", stdin);
    int T;
    cin >> T;
    while (T-- > 0) {
        solve();
    }
    return 0;
}

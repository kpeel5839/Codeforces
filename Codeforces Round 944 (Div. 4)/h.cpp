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
    template <> struct hash<std::vector<int>> {
        size_t operator()(const std::vector<int> &v) const {
            size_t hash_value = 0;
            for (int i : v) {
                hash_value ^= std::hash<int>()(i);
            }
            return hash_value;
        }
    };
}

const ll MOD=1e7;
vl fact = {1};
ll pow_mod(ll x, ll p) {
    if (p == 0) {
        return 1;
    }
    if (p % 2 == 0) {
        ll y = pow_mod(x, p / 2);
        return (y * y) % MOD;
    }
    return (x * pow_mod(x, p - 1)) % MOD;
}
ll inv(ll x) {
    return pow_mod(x, MOD - 2);
}
ll cnk(ll n, ll k) {
    ll res = fact[n];
    res = (res * inv(fact[k])) % MOD;
    res = (res * inv(fact[n - k])) % MOD;
    return res;
}

int n;
vii b;

int idValue;
int sccValue;
vi idx;
stack<int>st;
vi already;
vii graph;

int scc(int x){
    idx[x]=++idValue;
    st.push(x);
    int mi=idx[x];
    for(int next:graph[x]){
        if(!idx[next]){
            mi=min(mi,scc(next));
        }else if(!already[next]){
            mi=min(mi,idx[next]);
        }
    }
    if(mi==idx[x]){
        sccValue++;
        while(st.size()!=0){
            int a=st.top();st.pop();
            already[a]=sccValue;
            if(a==x){
                break;
            }
        }
    }
    return mi;
}

int oppo(int a){
    if(a<0){//홀수로 반환
        return (abs(a)-1)*2+1;
    }
    return (a-1)*2;
}

void solve() {
    int n;cin>>n;
    b=vii(3,vi(n,0));
    for(int i=0;i<3;i++){
        for(int j=0;j<n;j++){
            cin>>b[i][j];
        }
    }
    idx=vi(n*2,0);
    already=vi(n*2,0);
    graph=vii(n*2);
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            int next=(j+1)%3;
            int aa=oppo(b[j][i]);
            int bb=oppo(b[next][i]);
            graph[aa%2==0?aa+1:aa-1].push_back(bb);
            graph[bb%2==0?bb+1:bb-1].push_back(aa);
        }
    }
    for(int i=0;i<n*2;i++){
        if(!idx[i]){
            scc(i);
        }
    }
    bool yes=true;
    for(int i=0;i<n*2;i+=2){
        if(already[i]==already[i+1]){
            yes=false;
            break;
        }
    }
    cout<<(yes?"YES":"NO")<<"\n";
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("h.input.txt", "r", stdin);
    int T;
    cin >> T;
    while (T-- > 0) {
        solve();
    }
    return 0;
}

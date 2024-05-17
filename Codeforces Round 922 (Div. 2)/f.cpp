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
typedef vector<double> vd;
typedef vector<vd> vdd;
typedef vector<vdd> vddd;
typedef vector<vddd> vdddd;

// namespace std {
//     template <> struct hash<std::vector<int>> {
//         size_t operator()(const std::vector<int> &v) const {
//             size_t hash_value = 0;
//             for (int i : v) {
//                 hash_value ^= std::hash<int>()(i);
//             }
//             return hash_value;
//         }
//     };
// }

// int idValue;
// int sccValue;
// vi idx;
// stack<int>st;
// vi already;
// vii graph;

// int scc(int x){
//     idx[x]=++idValue;
//     st.push(x);
//     int mi=idx[x];
//     for(int next:graph[x]){
//         if(!idx[next]){
//             mi=min(mi,scc(next));
//         }else if(!already[next]){
//             mi=min(mi,idx[next]);
//         }
//     }
//     if(mi==idx[x]){
//         sccValue++;
//         while(st.size()!=0){
//             int a=st.top();st.pop();
//             already[a]=sccValue;
//             if(a==x){
//                 break;
//             }
//         }
//     }
//     return mi;
// }

// int oppo(int a){
//     if(a<0){//홀수로 반환
//         return (abs(a)-1)*2+1;
//     }
//     return (a-1)*2;
// }

// const ll MOD=1e7;
// vl fact = {1};
// ll pow_mod(ll x, ll p) {
//     if (p == 0) {
//         return 1;
//     }
//     if (p % 2 == 0) {
//         ll y = pow_mod(x, p / 2);
//         return (y * y) % MOD;
//     }
//     return (x * pow_mod(x, p - 1)) % MOD;
// }
// ll inv(ll x) {
//     return pow_mod(x, MOD - 2);
// }
// ll cnk(ll n, ll k) {
//     ll res = fact[n];
//     res = (res * inv(fact[k])) % MOD;
//     res = (res * inv(fact[n - k])) % MOD;
//     return res;
// }

struct comp{
    bool operator()(ll a,ll b){
        return a<b;
    }
};
vi d;
vi p;
vi h;
ll n,k;
vii graph;
priority_queue<ll,vl,comp>pq;
int maxDepth;
void dfs(int cur){
    d[cur]=0;
    if(cur!=1){
        h[cur]=h[p[cur]]+1;
    }
    for(int next:graph[cur]){
        dfs(next);
        d[cur]=max(d[cur],d[next]+1);
    }
    sort(graph[cur].begin(),graph[cur].end(),[](int o1,int o2) {
        return d[o1]<d[o2];
    });
}
void solve() {
    cin>>n>>k;
    graph=vii(n+1);
    p=vi(n+1,0);
    p[1]=1;
    for(int i=2;i<=n;i++){
        cin>>p[i];
        graph[p[i]].push_back(i);
    }
    ll total=(n-1)*2;
    d=vi(n+1,0);
    h=vi(n+1,0);
    dfs(1);
    vi jumpGain;
    for(int i=1;i<=n;i++){
        if(graph[i].size()==0){
            int v=i;
            int jump=0;
            while(v>1){
                if(graph[p[v]].size()!=0&&graph[p[v]].back()==v){
                    v=p[v];
                    jump++;
                }else{
                    jump=jump+1-h[p[v]];
                    break;
                }
            }
            jumpGain.push_back(jump);
        }
    }
    sort(jumpGain.begin(),jumpGain.end(),[](int o1,int o2) {
        return o1>o2;
    });
    ++k;
    for(int i=0;i<k;i++){
        if(jumpGain.size()==i||jumpGain[i]<0){
            break;
        }
        cout<<jumpGain[i]<<"\n";
        total-=jumpGain[i];
    }
    cout<<total<<"\n";
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("f.input.txt", "r", stdin);
    solve();
    return 0;
}

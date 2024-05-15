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
    if(p == 0) {
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

void solve() {
    int n,k;cin>>n>>k;
    vl a(n);
    for(auto&v:a) cin>>v;
    ll inf=1e16;
    vll dp=vll(k+1,vl(n,inf));
    dp[0][0]=a[0];
    for(int i=0;i<n;i++){
        if(i!=0){
            for(int j=0;j<=k;j++){
                dp[j][i]=min(dp[j][i],dp[j][i-1]+a[i]);
            }
        }
        for(int j=1;j<=k;j++){
            ll right=i==n-1?inf:a[i+1];
            ll left=i-j<0?inf:a[i-j];
            for(int c=0;c<=k-j;c++){
                dp[j+c][i]=min(dp[j+c][i],(i-j-1<0?0:dp[c][i-j-1])+j*min(right,left)+(left==inf?0:left));
            }
        }
    }
    ll mi=1e18;
    for(int i=0;i<=k;i++){
        mi=min(mi,dp[i][n-1]);
    }
    cout<<mi<<"\n";
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("c.input.txt", "r", stdin);
    int T;
    cin >> T;
    while (T-- > 0) {
        solve();
    }
    return 0;
}
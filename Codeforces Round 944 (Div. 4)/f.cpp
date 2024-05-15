t#include <algorithm>
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

void solve() {
    double rr;cin>>rr;
    ll l=1;
    ll r=rr;
    ll lastR=1;
    while(l<=r){
        ll m=(l+r)/2;
        if(pow(rr,2ll)+pow(m,2ll)<pow(rr+1ll,2)){
            lastR=m;
            l=m+1;
        }else{
            r=m-1;
        }
    }
    ll answer=(lastR*2ll+1ll)*4ll;
    if(lastR==rr){
        answer-=4ll;
    }
    for(ll i=1;i<rr;i++){
        ll left=1;
        ll right=i;
        ll lowerLastR=INF;
        while(left<=right){
            ll mid=(left+right)/2;
            if(pow(rr,2)<=pow(i,2ll)+pow(mid,2ll)){
                lowerLastR=mid;
                right=mid-1;
            }else{
                left=mid+1;
            }
        }
        left=1;
        right=i;
        ll upperLastR=-INF;
        while(left<=right){
            ll mid=(left+right)/2;
            if(pow(i,2ll)+pow(mid,2ll)<pow(rr+1ll,2)){
                upperLastR=mid;
                left=mid+1;
            }else{
                right=mid-1;
            }
        }
        if(lowerLastR<=upperLastR){
            ll points=upperLastR-lowerLastR+1;
            answer+=points*2*4;
            if(upperLastR==i){
                answer-=4;
            }
        }
    }
    cout<<answer<<"\n";
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

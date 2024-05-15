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

struct comp{
    bool operator()(ll a,ll b){
        return a<b;
    }
};

void solve() {
    int n,k;cin>>n>>k;
    vll a(n,vl(2,0));
    for(int i=0;i<n;i++){
        cin>>a[i][0];
    }
    for(int i=0;i<n;i++){
        cin>>a[i][1];
    }
    sort(a.begin(),a.end(),[](vl o1,vl o2){
        if(o1[1]==o2[1]){
            return o1[0]<o2[0];
        }
        return o1[1]>o2[1];
    });
    priority_queue<int,vector<int>,comp>pq;
    ll sum=0;
    vl ltr(n,-inf);
    for(int i=0;i<n;i++){
        pq.push(a[i][0]);
        sum-=a[i][0];
        while(pq.size()>k){
            sum+=pq.top();pq.pop();
        }
        if(pq.size()==k){
            ltr[i]=sum;
        }
    }
    vl rtl(n,0);
    sum=0;
    for(int i=n-1;0<=i;i--){
        if(a[i][0]<a[i][1]){
            sum+=(a[i][1]-a[i][0]);
        }
        rtl[i]=sum;
    }
    ll answer=0;
    for(int i=k;i<n;i++){
        answer=max(answer,rtl[i]+(i==0?0:ltr[i-1]));
    }
    cout<<answer<<"\n";
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("d.input.txt", "r", stdin);
    int T;
    cin >> T;
    while (T-- > 0) {
        solve();
    }
    return 0;
}

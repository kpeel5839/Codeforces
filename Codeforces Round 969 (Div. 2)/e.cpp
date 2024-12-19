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
typedef vector<string> vs;
typedef vector<vs> vss;
typedef vector<vss> vsss;
typedef vector<vsss> vssss;
typedef vector<char> vc;
typedef vector<vc> vcc;
typedef vector<vcc> vccc;
typedef vector<vccc> vcccc;

#define rep(x, y, z) for (int x = (y); x <= (z); ++x)
#define per(x, y, z) for (int x = (y); x >= (z); --x)

template <typename T>
void chkmin(T &x, T y)
{
    if (x > y)
        x = y;
}
template <typename T>
void chkmax(T &x, T y)
{
    if (x < y)
        x = y;
}

// template<int mod>
// inline unsigned int down(unsigned int x) {
// 	return x >= mod ? x - mod : x;
// }

// template<int mod>
// struct Modint {
// 	unsigned int x;
// 	Modint() = default;
// 	Modint(unsigned int x) : x(x) {}
// 	friend istream& operator>>(istream& in, Modint& a) {return in >> a.x;}
// 	friend ostream& operator<<(ostream& out, Modint a) {return out << a.x;}
// 	friend Modint operator+(Modint a, Modint b) {return down<mod>(a.x + b.x);}
// 	friend Modint operator-(Modint a, Modint b) {return down<mod>(a.x - b.x + mod);}
// 	friend Modint operator*(Modint a, Modint b) {return 1ULL * a.x * b.x % mod;}
// 	friend Modint operator/(Modint a, Modint b) {return a * ~b;}
// 	friend Modint operator^(Modint a, int b) {Modint ans = 1; for(; b; b >>= 1, a *= a) if(b & 1) ans *= a; return ans;}
// 	friend Modint operator~(Modint a) {return a ^ (mod - 2);}
// 	friend Modint operator-(Modint a) {return down<mod>(mod - a.x);}
// 	friend Modint& operator+=(Modint& a, Modint b) {return a = a + b;}
// 	friend Modint& operator-=(Modint& a, Modint b) {return a = a - b;}
// 	friend Modint& operator*=(Modint& a, Modint b) {return a = a * b;}
// 	friend Modint& operator/=(Modint& a, Modint b) {return a = a / b;}
// 	friend Modint& operator^=(Modint& a, int b) {return a = a ^ b;}
// 	friend Modint& operator++(Modint& a) {return a += 1;}
// 	friend Modint operator++(Modint& a, int) {Modint x = a; a += 1; return x;}
// 	friend Modint& operator--(Modint& a) {return a -= 1;}
// 	friend Modint operator--(Modint& a, int) {Modint x = a; a -= 1; return x;}
// 	friend bool operator==(Modint a, Modint b) {return a.x == b.x;}
// 	friend bool operator!=(Modint a, Modint b) {return !(a == b);}
// };

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

// const int N=1e6+100,mod=998244353;
// typedef Modint<mod> mint;
// mint a[N],inv[N];

vl edges;
vl depth;
vll graph;
vector<set<int>> paths;
map<int, vector<int>> edgeToPaths;
ll n, w;

void getDepth(int node, int des, int parent)
{
    depth[node] = des;
    for (int next : graph[node])
    {
        if (next == parent)
        {
            continue;
        }
        getDepth(next, des + 1, node);
    }
}

void check(int start)
{
    set<int> path;
    int initialStart = start;
    int next = start == n ? 1 : start + 1;
    // cout << "start: " << start << " next: " << next << "\n";
    if (depth[start] < depth[next])
    {
        int tmp = start;
        start = next;
        next = tmp;
    }
    while (depth[start] != depth[next])
    {
        path.insert(start);
        start = edges[start];
    }
    while (start != next)
    {
        path.insert(start);
        path.insert(next);
        start = edges[start];
        next = edges[next];
    }
    // cout << "path: ";
    for (auto &v : path)
    {
        // cout << v << " ";
        if (edgeToPaths.find(v) == edgeToPaths.end())
        {
            edgeToPaths[v] = vector<int>();
        }
        edgeToPaths[v].push_back(initialStart);
    }
    // cout << "\n";
    paths[initialStart] = path;
}

void solve()
{
    cin >> n >> w;
    graph = vll(n + 1);
    depth = vl(n + 1, 0);
    edges = vl(n + 1);
    paths = vector<set<int>>(n + 1);
    edgeToPaths = map<int, vector<int>>();
    for (int i = 0; i < n - 1; i++)
    {
        ll parent;
        cin >> parent;
        graph[parent].push_back(i + 2);
        graph[i + 2].push_back(parent);
        edges[i + 2] = parent;
    }
    getDepth(1, 0, -1);
    for (int i = 1; i <= n; i++)
    {
        check(i);
    }
    // for (int i = 1; i <= 4; i++)
    // {
    //     cout << i << ": ";
    //     for (auto &v : edgeToPaths[i])
    //     {
    //         cout<<v<<" ";
    //     }
    //     cout<<'\n';
    // }
    ll spare = 0;
    ll remain = n;
    for (int i = 0; i < n - 1; i++)
    {
        ll a, b;
        cin >> a >> b;
        spare += b * 2;
        for (auto &v : edgeToPaths[a])
        {
            paths[v].erase(a);
            if (paths[v].size() == 0)
            {
                remain--;
            }
        }
        // cout << remain * (w - spare / 2) + spare << " " << remain << "\n";
        cout << remain * (w - spare / 2) + spare << " ";
    }
    cout << "\n";
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // rep(i,2,N-1) inv[i]=(mod-mod/i)*inv[mod%i];
    freopen("e.input.txt", "r", stdin);
    int T;
    cin >> T;
    while (T-- > 0)
    {
        solve();
    }
    return 0;
}

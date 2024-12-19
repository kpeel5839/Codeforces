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

vl answer;
ll n;
vl a;
vl b;
vl sum;
int cnt = 0;

// void dfs(ll skipValue, ll prevSkipIndex, ll skipIndex)
// {
//     if (answer[skipIndex] >= sum[skipIndex] - skipValue)
//     {
//         return;
//     }
//     answer[skipIndex] = max(answer[skipIndex], sum[skipIndex] - skipValue);
//     // if (answer[prevSkipIndex][skipIndex] >= sum[skipIndex] - skipValue)
//     // {
//     //     return;
//     // }
//     // answer[prevSkipIndex][skipIndex] = max(answer[prevSkipIndex][skipIndex], sum[skipIndex] - skipValue);
//     unordered_map<ll, ll> m;
//     for (int i = prevSkipIndex + 1; i <= skipIndex; i++)
//     {
//         if (skipIndex >= b[i])
//         {
//             continue;
//         }
//         if (m.find(b[i]) == m.end())
//         {
//             m[b[i]] = i;
//         }
//         else
//         {
//             if (a[m[b[i]]] > a[i])
//             {
//                 m[b[i]] = i;
//             }
//         }
//     }
//     vll arr;
//     for (auto &v : m)
//     {
//         arr.push_back({v.first, v.second});
//     }
//     sort(arr.begin(), arr.end(), [](vl &o1, vl &o2)
//          {
//             if(a[o1[1]]==a[o2[1]])
//             {
//                 return a[o1[1]] < a[o2[1]];
//             }
//             return o1[0] > o2[0]; });
//     for (auto &v : arr)
//     {
//         dfs(skipValue += a[v[1]], skipIndex, v[0]);
//     }
// }

vlll graph;
struct comp
{
    bool operator()(vl &o1, vl &o2)
    {
        return o1[1] > o2[1];
    }
};

void dijkstra()
{
    answer = vl(n + 1, 1e18);
    priority_queue<vl, vll, comp> pq;
    pq.push({1, 0});
    answer[1] = 0;
    while (!pq.empty())
    {
        vl v = pq.top();
        pq.pop();
        if (answer[v[0]] < v[1])
        {
            continue;
        }
        for (auto &u : graph[v[0]])
        {
            if (answer[u[0]] > v[1] + u[1])
            {
                answer[u[0]] = v[1] + u[1];
                pq.push({u[0], v[1] + u[1]});
            }
        }
    }
}

void solve()
{
    cin >> n;
    sum = vl(n + 1, 0);
    answer = vl(n + 1, 0);
    // answer = vll(n + 1, vl(n + 1, 0));
    a = vl(n + 1, 0);
    b = vl(n + 1, 0);
    graph = vlll(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }
    for (int i = 1; i <= n; i++)
    {
        graph[i].push_back({b[i], a[i]});
        for (int j = 2; j < b[i]; j++)
        {
            if (b[i] < b[j])
            {
                graph[i].push_back({j, a[j]});
            }
        }
    }
    dijkstra();
    ll ans = 0;
    // for (int i = 1; i < answer.size(); i++)
    // {
    //     cout << answer[i] << "(" << sum[i] << ")" << " ";
    // }
    // cout << "\n";
    for (int i = 1; i < answer.size(); i++)
    {
        if (answer[i] == 1e18)
        {
            continue;
        }
        ans = max(ans, sum[i] - answer[i]);
    }
    cout << ans << "\n";
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // rep(i,2,N-1) inv[i]=(mod-mod/i)*inv[mod%i];
    freopen("d.input.txt", "r", stdin);
    int T;
    cin >> T;
    while (T-- > 0)
    {
        solve();
    }
    return 0;
}

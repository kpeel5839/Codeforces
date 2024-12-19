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

vc leafs;
char root;
string s;
vii graph;
int cnt = 0;

void dfs(int parent, int cur)
{
    for (int next : graph[cur])
    {
        if (parent == next)
        {
            continue;
        }
        dfs(cur, next);
    }
    if (parent != -1 && graph[cur].size() == 1)
    {
        leafs.push_back(s[cur]);
    }
}

void solve()
{
    int n;
    cin >> n;
    graph = vii(n + 1);
    leafs = vc();
    // if (cnt == 1851)
    // {
    //     cout << n;
    // }
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a - 1].push_back(b - 1);
        graph[b - 1].push_back(a - 1);
        // if (cnt == 1851)
        // {
        //     cout << a << b;
        // }
    }
    cin >> s;
    // if (cnt == 1851)
    // {
    //     cout << s << "\n";
    // }
    int allCountOfQuestion = 0;
    for (auto &v : s)
    {
        if (v == '?')
        {
            allCountOfQuestion++;
        }
    }
    root = s[0];
    dfs(-1, 0);
    int oneCount = 0;
    int zeroCount = 0;
    int questionCount = 0;
    for (int i = 0; i < leafs.size(); i++)
    {
        if (leafs[i] == '0')
        {
            zeroCount++;
        }
        if (leafs[i] == '1')
        {
            oneCount++;
        }
        if (leafs[i] == '?')
        {
            questionCount++;
        }
    }
    int answer = 0;
    if (root == '?')
    {
        if (zeroCount < oneCount)
        {
            root = '0';
        }
        else
        {
            root = '1';
        }
        int cnt = 0;
        for (int i = 0; i < leafs.size(); i++)
        {
            if (leafs[i] == '?')
            {
                cnt++;
                if (cnt % 2 == 1)
                {
                    leafs[i] = root;
                }
                else
                {
                    leafs[i] = root == '0' ? '1' : '0';
                }
            }
        }
        if (zeroCount == oneCount && questionCount % 2 == 1 && allCountOfQuestion % 2 == 1)
        {
            answer++;
        }
    }
    else
    {
        int cnt = 0;
        for (int i = 0; i < leafs.size(); i++)
        {
            if (leafs[i] == '?')
            {
                cnt++;
                if (cnt % 2 == 1)
                {
                    leafs[i] = root == '0' ? '1' : '0';
                }
                else
                {
                    leafs[i] = root;
                }
            }
        }
    }
    for (int i = 0; i < leafs.size(); i++)
    {
        if (root != leafs[i])
        {
            answer++;
        }
    }
    cout << answer << "\n";
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
        cnt++;
        solve();
    }
    return 0;
}

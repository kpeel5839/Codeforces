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
int n, q;
map<int, int> m;
vll query;
vl arr;
vl answer;
vll recorded;

struct comp
{
    bool operator()(ll &o1, ll &o2)
    {
        return o1 > o2;
    }
};

int leftLowerBound(ll value)
{
    ll l = 0;
    ll r = (ll)query.size() - 1;
    ll ans = -1;

    while (l <= r)
    {
        ll m = (l + r) / 2;

        if (query[m][0] >= value)
        {
            r = m - 1;
            ans = m;
        }
        else
        {
            l = m + 1;
        }
    }

    return ans;
}
int rightUpperBound(ll value)
{
    ll l = 0;
    ll r = (ll)query.size() - 1;
    ll ans = -2;

    while (l <= r)
    {
        ll m = (l + r) / 2;

        if (query[m][0] <= value)
        {
            l = m + 1;
            ans = m;
        }
        else
        {
            r = m - 1;
        }
    }

    return ans;
}

void removeRange(ll left, ll right, int sequence)
{
    ll newValue = 0;
    for (ll i = 30; 0 <= i; i--)
    {
        ll value = 1 << i;
        bool leftOne = (left & (1 << i)) != 0;
        bool rightOne = (right & (1 << i)) != 0;

        int leftBound = -1;
        int rightBound = -2;

        if (leftOne && rightOne) // 1 1
        {
            // cout << "1 1 " << newValue + value << " " << newValue + value + (value - 1) << "\n";
            leftBound = leftLowerBound(newValue + value);
            rightBound = rightUpperBound(newValue + value + (value - 1));
        }
        else if (leftOne && !rightOne) // 1 0
        {
            // cout << "1 0 " << newValue << " " << newValue + value - 1 << "\n";
            leftBound = leftLowerBound(newValue);
            rightBound = rightUpperBound(newValue + (value - 1));
            newValue += value;
        }
        else if (!leftOne && rightOne) // 0 1
        {
            // cout << "0 1 " << newValue << " " << newValue + value << "\n";
            newValue += value;
        }
        else // 0 0
        {
            continue;
        }

        // cout << "left bound and right bound " << leftBound << " " << rightBound << "\n";

        if (leftBound > rightBound || leftBound < 0 || rightBound < 0)
        {
            continue;
        }

        // cout << query[leftBound][0] << " " << query[rightBound][0] << "\n";

        recorded[leftBound].push_back(sequence);
        if (rightBound >= (ll)recorded.size() - 1)
        {
            continue;
        }
        recorded[rightBound + 1].push_back(-sequence);
    }
}

void getAnswer()
{
    recorded = vll(query.size(), vl());
    ll right = 0;
    for (int i = n - 1; 0 <= i; i--)
    {
        removeRange(arr[i], right, n - i);
        // cout << "------------\n";
        right ^= arr[i];
    }

    priority_queue<ll, vl, comp> pq;

    for (int i = 0; i < query.size(); i++)
    {
        for (auto &v : recorded[i])
        {
            if (v < 0)
            {
                m[abs(v)]--;
            }
            else
            {
                pq.push(v);
                m[v]++;
            }
        }

        while (!pq.empty() && m[pq.top()] == 0)
        {
            pq.pop();
        }

        if (pq.empty())
        {
            continue;
        }
        else
        {
            answer[query[i][1]] = pq.top() - 1;
            // cout << answer[query[i][1]] << "\n";
        }
    }
}

void solve()
{
    cin >> n >> q;
    arr = vl(n, 0);
    query = vll(q, vl(2, 0));
    m = map<int, int>();
    answer = vl(q, n);
    for (auto &v : arr)
    {
        cin >> v;
    }
    for (int i = 0; i < q; i++)
    {
        cin >> query[i][0];
        query[i][1] = i;
    }
    sort(query.begin(), query.end(), [](vl &o1, vl &o2)
         { return o1[0] < o2[0]; });
    getAnswer();
    for (auto &v : answer)
    {
        cout << v << " ";
    }
    cout << "\n";
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

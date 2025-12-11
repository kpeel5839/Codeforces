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

template<typename T>
void chkmin(T &x, T y) { if (x > y) x = y; }
template<typename T>
void chkmax(T &x, T y) { if (x < y) x = y; }

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

struct comp {
  bool operator()(vi &o1, vi &o2) {
    return max(o1[2], o1[3]) > max(o2[2], o2[3]);
  }
};

void solve() {
  int n;
  cin >> n;
  vb visited(n, false);
  priority_queue<vi, vii, comp> pq; // {idx1, idx2, element, element}
  vi arr;
  vii edges(n, vi(2, 0));
  for (int i = 0; i < n; i++) {
    int v;
    cin >> v;
    arr.push_back(v);
  }

  int LEFT = 0;
  int RIGHT = 1;

  for (int i = 0; i < n; i++) {
    if (i == 0) {
      edges[i][LEFT] = n - 1;
      edges[i][RIGHT] = i + 1;
    } else if (i == n - 1) {
      edges[i][LEFT] = i - 1;
      edges[i][RIGHT] = 0;
    } else {
      edges[i][LEFT] = i - 1;
      edges[i][RIGHT] = i + 1;
    }

    pq.push({edges[i][LEFT], i, arr[i], arr[edges[i][LEFT]]});
    pq.push({i, edges[i][RIGHT], arr[i], arr[edges[i][RIGHT]]});
  }

  ll answer = 0;

  for (int i = 0; i < n - 1; i++) {
    vi selected;
    while (true) {
      vi points = pq.top();
      pq.pop();
      if (visited[points[0]] || visited[points[1]]) {
        continue;
      }
      selected = points;
      break;
    }

    int idx1 = selected[0];
    int idx2 = selected[1];
    // cout << "idxes : " << idx1 << " " << idx2 << "\n";

    // idx1, idx2 중 큰 애만 살려야함, 같은 경우 오른쪽만 살림
    if (arr[idx1] <= arr[idx2]) {
      // 오른쪽 애 살림
      visited[idx1] = true;
      answer += (ll) arr[idx2];
      // cout << arr[idx2] << "\n";

      // idx2의 왼쪽을 죽였으니, 왼쪽왼쪽을 가져와야함
      int leftleft = edges[idx1][LEFT];
      edges[leftleft][RIGHT] = idx2;
      edges[idx2][LEFT] = leftleft;
      pq.push({leftleft, idx2, arr[idx2], arr[leftleft]});
    } else {
      // 왼쪽 애 살림
      visited[idx2] = true;
      answer += (ll) arr[idx1];
      // cout << arr[idx1] << "\n";

      // idx2를 죽였으니 idx2의 right를 가져와야함
      int rightright = edges[idx2][RIGHT];
      edges[rightright][LEFT] = idx1;
      edges[idx1][RIGHT] = rightright;
      pq.push({idx1, rightright, arr[idx1], arr[rightright]});
    }
  }

  // for (int i = 0; i < n; i++) {
  // cout << "i : " << i << " left : " << edges[i][LEFT] << " right : " << edges[i][RIGHT] << "\n";
  // }

  cout << answer << "\n";
}

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  // rep(i,2,N-1) inv[i]=(mod-mod/i)*inv[mod%i];
  freopen("Codeforces_Round_1064_(Div._2)/c.input.txt", "r", stdin);
  int T;
  cin >> T;
  while (T-- > 0) {
    solve();
  }
  return 0;
}
